#pragma once

#include "PathFinding/PathFinding.h"
#include "PathFinding/PathNode.h"
#include "Tiles/TileBase.h"
#include "Constants/Constants.h"
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
			BuildPath(currentNode);

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

			if (GetNodeInPath(closedPath, tile) != nullptr)
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

PathNode* PathFinding::GetNodeAtIndex(int index)
{
	if (index >= 0 && index < finalPath.size())
	{
		return finalPath.at(index);
	}

	return nullptr;
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
		state = Reached;
		return; 
	}

	PathNode* node = new PathNode(currentTile);
	AddNodeToPath(openPath, node);

	state = PathFindingState::Searching;
}

bool PathFinding::IsPathSearching()
{
	return state == PathFindingState::Searching;
}

bool PathFinding::IsPathFound()
{
	return state == PathFindingState::Found;
}

bool PathFinding::IsPathReached()
{
	return state == PathFinding::Reached;
}

void PathFinding::Reset()
{
	state = PathFindingState::Idle;
}

void PathFinding::ClearAllPaths()
{
	ClearPath(openPath);
	ClearPath(closedPath);
	finalPath.clear(); //should be empty by now
	destinationTileIndex = -1; // reset
}

void PathFinding::ClearPath(std::vector<PathNode*>& targetPath)
{
	while (targetPath.size() > 0)
	{
		PathNode* node = targetPath.back();
		delete node;

		targetPath.pop_back();
	}
}

void PathFinding::AddNodeToPath(std::vector<PathNode*>& targetPath, PathNode* targetTile)
{
	targetPath.push_back(targetTile);
	SortPath(targetPath);
}

void PathFinding::SortPath(std::vector<PathNode*>& targetPath)
{
	std::sort(targetPath.begin(), targetPath.end(), PathNode::ComparePathNodes);
}

PathNode* PathFinding::GetNodeInPath(std::vector<PathNode*>& targetPath, TileBase* tile)
{
	int index = tileController.GetIndexForTile(tile);
	for (int i = 0; i < targetPath.size(); ++i)
	{
		PathNode* node = targetPath.at(i);
		int tileIndex = tileController.GetIndexForTile(node->GetTile());
		if (tileIndex == index)
		{
			return node;
		}
	}
	return nullptr;
}

void PathFinding::AddTile(std::vector<TileBase*>& targetPath, TileBase* currentTile, int surroundingX, int surroundingY)
{
	int x = tileController.GetTilePosition(currentTile->GetPositionX() - Constants::GAME_FIELD_OFFSET_X) + surroundingX;
	int y = tileController.GetTilePosition(currentTile->GetPositionY() - Constants::GAME_FIELD_OFFSET_Y) + surroundingY;

	TileBase* tile = tileController.GetTileAtPosition(x, y);

	if (tile != nullptr)
	{
		bool positionOutOfBound = tileController.IsPositionOutOfBound(x, y);

		if (tile->IsPassable() && !positionOutOfBound)
		{
			targetPath.push_back(tile);
		}
	}
}

void PathFinding::BuildPath(PathNode* node)
{
	do
	{
		if (node->GetParentNode() != nullptr)
		{
			finalPath.insert(finalPath.begin(), node);
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
