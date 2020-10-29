#pragma once

class TileBase
{
public:
	TileBase(float posX, float posY, bool passable = true);
	virtual ~TileBase();

	void SetPath(bool value);
	bool IsPath();
	bool IsPassable();

	int GetPositionX();
	int GetPositionY();

private:
	bool pathTile;
	float passable;
	int positionX;
	int positionY;
};