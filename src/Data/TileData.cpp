#pragma once

#include "Data/TileData.h"

TileData::TileData(std::string tileString)
{
	tileType = GetTileTypeFromString(tileString);
}

TileData::TileType TileData::GetTileTypeFromString(std::string tileString)
{
	if (tileString == PASSABLE_TILE) return TileType::Passable;
	if (tileString == IMPASSABLE_TILE) return TileType::Impassable;
	if (tileString == SPAWN_POINT) return TileType::SpawnPoint;
	if (tileString == PLAYER_POINT) return TileType::PlayerPoint;
	
	//if all else fails
	return TileType::Impassable;
}
