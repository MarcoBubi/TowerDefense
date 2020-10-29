#pragma once

#include "Tiles/TileBase.h"

class PathNode
{
public:
	PathNode(TileBase* targetTile);
	~PathNode();

	bool CompareNodes(PathNode* nodeA, PathNode* nodeB);

	int GetG();
	int GetH();
	int GetF();
	void SetG(int value);
	void SetH(int value);

	TileBase* GetTile();
	PathNode* GetParentNode();
	void SetParentNode(PathNode* node);

	static bool ComparePathNodes(PathNode* nodeA, PathNode* nodeB);

private:
	TileBase* tile;
	int G;
	int H;
	PathNode* parentNode;
};