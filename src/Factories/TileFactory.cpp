#pragma once

#include "Factories/TileFactory.h"
#include "Tiles/ImpassableTile.h"
#include "Tiles/PassableTile.h"
#include "Tiles/PlayerPointTile.h"
#include "Tiles/SpawnPointTile.h"

TileBase* TileFactory::CreateTile(TileData::TileType type, float positionX, float positionY)
{
	switch (type)
	{
	case TileData::TileType::Passable:
		return new PassableTile(positionX, positionY);
		break;
	case TileData::TileType::Impassable:
		return new ImpassableTile(positionX, positionY);
		break;
	case TileData::TileType::SpawnPoint:
		return new SpawnPointTile(positionX, positionY);
		break;
	case TileData::TileType::PlayerPoint:
		return new PlayerPointTile(positionX, positionY);
		break;
	default:
		break;
	}
	return nullptr;
}
