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
