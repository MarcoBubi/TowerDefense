#pragma once

#include "PathFinding/PathNode.h"

PathNode::PathNode(TileBase* targetTile) :
	tile(targetTile)
{

}

PathNode::~PathNode()
{

}

bool PathNode::CompareNodes(PathNode* nodeA, PathNode* nodeB)
{
	return nodeA->GetF() < nodeB->GetF();
}

int PathNode::GetG()
{
	return G;
}

int PathNode::GetH()
{
	return H;
}

int PathNode::GetF()
{
	return G + H;
}

void PathNode::SetG(int value)
{
	G = value;
}

void PathNode::SetH(int value)
{
	H = value;
}

TileBase* PathNode::GetTile()
{
	return tile;
}

PathNode* PathNode::GetParentNode()
{
	return parentNode;
}

void PathNode::SetParentNode(PathNode* node)
{
	parentNode = node;
}

bool PathNode::ComparePathNodes(PathNode* nodeA, PathNode* nodeB)
{
	return nodeA->GetF() < nodeB->GetF();
}
