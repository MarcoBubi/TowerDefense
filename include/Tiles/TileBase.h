#pragma once

class TileBase
{
public:
	TileBase(float posX, float posY, bool passable = true);
	virtual ~TileBase();

	bool IsPassable();

	int GetPositionX();
	int GetPositionY();

private:
	float passable;
	int positionX;
	int positionY;
};