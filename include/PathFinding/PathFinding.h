#pragma once

#include "Controllers/TileController.h"
#include <vector>

class TileBase;
class PathNode;

class PathFinding
{
public:
	enum PathFindingState
	{
		Idle = 0,
		Searching = 1,
		Found = 2,
		Reached = 3
	};

	PathFinding(TileController& tC);
	~PathFinding();

	void Update(float deltaTime);

	PathNode* GetNodeAtIndex(int index);
	void FindPath(TileBase* currentTile, TileBase* targetTile);
	bool IsPathSearching();
	bool IsPathFound();
	bool IsPathReached();
	void Reset();

private:
	void ClearAllPaths();
	void ClearPath(std::vector<PathNode*>& targetPath);
	void AddNodeToPath(std::vector<PathNode*>& targetPath, PathNode* targetTile);
	void SortPath(std::vector<PathNode*>& targetPath);
	PathNode* GetNodeInPath(std::vector<PathNode*>& targetPath, TileBase* tile);

	void AddTile(std::vector<TileBase*>& targetPath, TileBase* currentTile, int surroundingX, int surroundingY);
	void BuildPath(PathNode* node);

	int GetDistance(TileBase* tile, TileBase* destinationTile);

	bool pathFound = false;
	int destinationTileIndex = -1; // out of range
	TileController& tileController;

	PathFindingState state = PathFindingState::Idle;
	std::vector<PathNode* > openPath;
	std::vector<PathNode* > closedPath;
	std::vector<PathNode* > finalPath;

};