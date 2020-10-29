#pragma once

#include "Factories/TileFactory.h"
#include "Data/TileData.h"
#include "Tiles/TileBase.h"
#include "Controllers/ControllerBase.h"
#include <vector>

class TileController : public ControllerBase
{
public:
	TileController(int screenHeight, int screenWidth);
	~TileController();

	void Start() override;
	void Update(float deltaTime) override;

	void CreateTiles(std::vector<TileData*> tilesData);
	TileBase* GetTileAtPosition(int positionX, int positionY);
	bool IsPositionOutOfBound(int positionX, int positionY);

	std::vector<TileBase*> GetSpawnPoints();
	TileBase& GetRandomSpawnPoint();
	std::vector<TileBase*> GetPlayerPoints();

private:
	int GetCoordinateFor(int value, int offSet);
	int GetTileIndexForPosition(int x, int y);

	int horizontalTiles;
	int verticalTiles;
	std::vector<TileBase*> spawnPoints;
	std::vector<TileBase*> playerPoints;
	TileFactory* tileFactory = nullptr;
	TileBase** tiles = nullptr;
};