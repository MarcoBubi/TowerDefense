#pragma once

#include "Factories/TileFactory.h"
#include "Tiles/TileBase.h"
#include "Controllers/ControllerBase.h"
#include <vector>

class TileController : public ControllerBase
{
public:
	TileController(int screenHeight, int screenWidth, TileFactory& tF);
	~TileController();

	void Start() override;
	void Update(float deltaTime) override;

	void CreateTiles(std::vector<TileData*> tilesData);
	int GetTilePosition(int position);
	TileBase* GetTileAtPosition(int positionX, int positionY) const;
	TileBase* GetTileAtIndex(int index) const;
	int GetIndexForTile(TileBase* tile) const;
	int GetIndexForPosition(int x, int y) const;
	bool IsPositionOutOfBound(int positionX, int positionY) const;

	int GetNumberOfTiles() const;
	std::vector<TileBase*> GetSpawnPoints() const;
	TileBase& GetRandomSpawnPoint();
	TileBase& GetRandomPlayerPoint();
	std::vector<TileBase*> GetPlayerPoints() const;

private:
	int GetCoordinateFor(int value, int offSet) const;
	int GetTileIndexForPosition(int x, int y) const;

	int horizontalTiles;
	int verticalTiles;
	std::vector<TileBase*> spawnPoints;
	std::vector<TileBase*> playerPoints;
	TileFactory& tileFactory;
	TileBase** tiles = nullptr;
};