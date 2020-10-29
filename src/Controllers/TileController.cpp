#pragma once

#include "Controllers/TileController.h"
#include "Constants/Constants.h"
#include "Data/TileData.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

TileController::TileController(int screenHeight, int screenWidth, TileFactory& tF) : 
	horizontalTiles(screenHeight / Constants::TILE_SIZE),
	verticalTiles(screenWidth / Constants::TILE_SIZE),
	tileFactory(tF)
{
	srand(time(NULL)); // Don't feel like implementing a better solution atm.

	int numberOfTiles = horizontalTiles * verticalTiles;
	tiles = new TileBase*[numberOfTiles];

	for (int i = 0; i < numberOfTiles; ++i)
	{
		tiles[i] = nullptr;
	}
}

TileController::~TileController()
{
	if (tiles != nullptr)
	{
		int numberOfTiles = horizontalTiles * verticalTiles;

		for (int i = 0; i < numberOfTiles; ++i)
		{
			delete tiles[i];
			tiles[i] = nullptr;
		}
	}
	delete[] tiles;
	tiles = nullptr;
}

void TileController::Start()
{

}

void TileController::Update(float deltaTime)
{

}

void TileController::CreateTiles(std::vector<TileData*> tilesData)
{
	int numberOfTiles = horizontalTiles * verticalTiles;
	int tileIndex = 0;
	float tileX = Constants::GAME_FIELD_OFFSET_X;
	float tileY = Constants::GAME_FIELD_OFFSET_Y;

	for (int vert = 0; vert < verticalTiles; ++vert)
	{
		for (int horz = 0; horz < horizontalTiles; ++horz)
		{
			TileBase* tile = tileFactory.CreateTile(tilesData[tileIndex]->tileType, tileX, tileY);
			tiles[tileIndex] = tile;
			TileData::TileType tileType = tilesData[tileIndex]->tileType;

			if (tileType == TileData::TileType::PlayerPoint)
			{
				playerPoints.push_back(tile);
			}

			if (tileType == TileData::TileType::SpawnPoint)
			{
				spawnPoints.push_back(tile);
			}

			++tileIndex;
			tileX += Constants::TILE_SIZE;
		}

		tileY += Constants::TILE_SIZE;
		tileX = Constants::GAME_FIELD_OFFSET_X;
	}
}

int TileController::GetTilePosition(int position)
{
	return (position / Constants::TILE_SIZE);
}

TileBase* TileController::GetTileAtPosition(int positionX, int positionY) const
{
	int coordinateX = GetCoordinateFor(positionX, Constants::GAME_FIELD_OFFSET_X);
	int coordinateY = GetCoordinateFor(positionY, Constants::GAME_FIELD_OFFSET_Y);

	return GetTileAtIndex(GetTileIndexForPosition(coordinateX, coordinateY));
}

TileBase* TileController::GetTileAtIndex(int index) const
{
	if (index >= 0 && index < GetNumberOfTiles())
	{
		return tiles[index];
	}

	return nullptr;
}

int TileController::GetIndexForTile(TileBase* tile) const
{
	return GetIndexForPosition(tile->GetPositionX(), tile->GetPositionY());
}

int TileController::GetIndexForPosition(int x, int y) const
{
	int coordinateX = GetCoordinateFor(x, Constants::GAME_FIELD_OFFSET_X);
	int coordinateY = GetCoordinateFor(y, Constants::GAME_FIELD_OFFSET_Y);
	return GetTileIndexForPosition(coordinateX, coordinateY);
}

bool TileController::IsPositionOutOfBound(int positionX, int positionY) const
{
	return GetTileAtPosition(positionX, positionY) == nullptr;
}

int TileController::GetNumberOfTiles() const
{
	return horizontalTiles * verticalTiles;;
}

std::vector<TileBase*> TileController::GetSpawnPoints() const
{
	return spawnPoints;
}

TileBase& TileController::GetRandomSpawnPoint()
{
	int spawnPointsSize = spawnPoints.size();

	int index = rand() % spawnPointsSize;

	return *spawnPoints[index];
}

TileBase& TileController::GetRandomPlayerPoint()
{
	int spawnPointsSize = playerPoints.size();

	int index = rand() % spawnPointsSize;

	return *playerPoints[index];
}

std::vector<TileBase*> TileController::GetPlayerPoints() const
{
	return playerPoints;
}

int TileController::GetCoordinateFor(int value, int offSet) const
{
	return  (offSet + value) / Constants::TILE_SIZE;
}

int TileController::GetTileIndexForPosition(int x, int y) const
{
	return x + (y * horizontalTiles);
}
