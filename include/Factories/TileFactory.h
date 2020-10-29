#pragma once

#include "Tiles/TileBase.h"
#include "Data/TileData.h"

class TileFactory
{
public:
	TileBase* CreateTile(TileData::TileType type, float positionX, float positionY);

}; 
