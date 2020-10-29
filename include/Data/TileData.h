#pragma once

#include <string>

struct TileData
{
public:
	enum class TileType
	{
		Passable = 1,
		Impassable = 2,
		SpawnPoint = 3,
		PlayerPoint = 4
	};

	TileType tileType;

	TileData(std::string tileString);
private:
	TileData::TileType GetTileTypeFromString(std::string tileString);

	const std::string PASSABLE_TILE = "=";
	const std::string IMPASSABLE_TILE = "/";
	const std::string SPAWN_POINT = "X";
	const std::string PLAYER_POINT = "P";
};