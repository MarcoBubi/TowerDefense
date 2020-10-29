#pragma once

#include "Tiles/TileBase.h"

TileBase::TileBase(float posX, float posY, bool passable) :
	positionX(posX),
	positionY(posY),
	passable(passable)
{

}

TileBase::~TileBase()
{

}

void TileBase::SetPath(bool value)
{
	if (passable)
	{
		pathTile = true;
	}
}

bool TileBase::IsPath()
{
	return pathTile;
}

bool TileBase::IsPassable()
{
	return passable;
}

int TileBase::GetPositionX()
{
	return positionX;
}

int TileBase::GetPositionY()
{
	return positionY;
}
