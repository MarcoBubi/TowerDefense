#pragma once

#include "PathFinding/PathFinding.h"
#include "PathFinding/PathNode.h"
#include "Tiles/TileBase.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>

PathFinding::PathFinding(TileController& tC) :
	tileController(tC)
{

}

PathFinding::~PathFinding()
{

}

void PathFinding::Update(float deltaTime)
{
	while (state == PathFindingState::Searching && destinationTileIndex != 1)
	{
		if (openPath.size() == 0)
		{
			return;
		}

		PathNode* currentNode = openPath.front();
		closedPath.push_back(currentNode);
		openPath.erase(openPath.begin());

		int currentNodeIndex = tileController.GetIndexForTile(currentNode->GetTile());
		
		if (currentNodeIndex == destinationTileIndex)
		{
			BuildTargetPath(currentNode);

			state = PathFindingState::Found;
			return;
		}

		std::vector<TileBase* > surroundingTiles;

		AddTile(surroundingTiles, currentNode->GetTile(), 0, -1); // above
		AddTile(surroundingTiles, currentNode->GetTile(), 0, 1); // below
		AddTile(surroundingTiles, currentNode->GetTile(), -1, 0); // left
		AddTile(surroundingTiles, currentNode->GetTile(), 1, 0); // right

		for (int i = 0; i < surroundingTiles.size(); ++i)
		{
			TileBase* tile = surroundingTiles.at(i);

			if (GetNodeInPath(closedPath, tile) == nullptr)
			{
				continue;
			}

			if (GetNodeInPath(openPath, tile) == nullptr)
			{
				PathNode* node = new PathNode(tile);

				node->SetParentNode(currentNode);
				node->SetG(currentNode->GetG() + 1);

				TileBase* destinationTile = tileController.GetTileAtIndex(destinationTileIndex);
				int distance = GetDistance(tile, destinationTile);
				node->SetH(distance);

				AddNodeToPath(openPath, node);
			}
			else
			{
				PathNode* node = GetNodeInPath(openPath, tile);

				if (currentNode->GetG() + 1 < node->GetG())
				{
					node->SetG(currentNode->GetG() + 1);
					node->SetParentNode(currentNode);

					SortPath(openPath);
				}
			}
		}
	}
}

void PathFinding::FindPath(TileBase* currentTile, TileBase* targetTile)
{
	if (state != PathFindingState::Idle)
	{
		return;
	}

	for (int i = 0; i < tileController.GetNumberOfTiles(); ++i)
	{
		TileBase* tile = tileController.GetTileAtIndex(i);
		if (tile != nullptr && tile->IsPassable())
		{
			tile->SetPath(true);
		}
	}

	ClearAllPaths();

	int currentTileIndex = tileController.GetIndexForTile(currentTile);
	destinationTileIndex = tileController.GetIndexForTile(targetTile);

	if (currentTileIndex == destinationTileIndex || !targetTile->IsPassable())
	{
		return; 
	}

	PathNode* node = new PathNode(currentTile);
	AddNodeToPath(openPath, node);
}

bool PathFinding::IsPathSearching()
{
	return state == PathFinding::PathFindingState::Searching;
}

void PathFinding::ClearAllPaths()
{
	ClearPath(openPath);
	ClearPath(closedPath);
	targetPath.clear(); //should be empty by now
}

void PathFinding::ClearPath(std::vector<PathNode*> targetPath)
{
	while (targetPath.size() > 0)
	{
		PathNode* node = targetPath.back();
		delete node;

		targetPath.pop_back();
	}
}

void PathFinding::AddNodeToPath(std::vector<PathNode*> targetPath, PathNode* targetTile)
{
	targetPath.push_back(targetTile);
	SortPath(targetPath);
}

void PathFinding::SortPath(std::vector<PathNode*> targetPath)
{
	std::sort(targetPath.begin(), targetPath.end(), PathNode::ComparePathNodes);
}

PathNode* PathFinding::GetNodeInPath(std::vector<PathNode*> targetPath, TileBase* tile)
{
	int index = tileController.GetIndexForTile(tile);
	for (int i = 0; i < targetPath.size(); ++i)
	{
		PathNode* node = openPath.at(i);
		if (tileController.GetIndexForTile(node->GetTile()) == index)
		{
			return node;
		}
	}
	return nullptr;
}

void PathFinding::AddTile(std::vector<TileBase*>& surroundingTiles, TileBase* currentTile, int surroundingX, int surroundingY)
{
	int x = tileController.GetTilePosition(currentTile->GetPositionX() + surroundingX);
	int y = tileController.GetTilePosition(currentTile->GetPositionY() + surroundingY);

	TileBase* tile = tileController.GetTileAtPosition(x, y);
	if (tile != nullptr && tile->IsPassable() && !tileController.IsPositionOutOfBound(x, y))
	{
		surroundingTiles.push_back(tile);
	}
}

void PathFinding::BuildTargetPath(PathNode* node)
{
	do
	{
		if (node->GetParentNode() != nullptr)
		{
			targetPath.insert(targetPath.begin(), node);
		}

		node->GetTile()->SetPath(true);
		node = node->GetParentNode();
	} 
	while (node != nullptr);
}

int PathFinding::GetDistance(TileBase* tile, TileBase* destinationTile)
{
	//Manhattan method: https://en.wikipedia.org/wiki/A*_search_algorithm#Pseudocode (for a grid videogame - Manhattan distance)

	int vertMoves = abs(tileController.GetTilePosition(destinationTile->GetPositionX() - tileController.GetTilePosition(tile->GetPositionX())));
	int horzMoves = abs(tileController.GetTilePosition(destinationTile->GetPositionY() - tileController.GetTilePosition(tile->GetPositionY())));

	return vertMoves + horzMoves;

}
