#pragma once

#include "Drawable.h"
#include "Tiles/TileBase.h"
#include <SDL.h>
#include <SDL_image.h>

#define IMG_PATH_T1 "resources/impassable_1.png"
#define IMG_PATH_T2 "resources/passable_1.png" 
// won't be here! will be in each view file

class TileViewBase : public Drawable
{
public:
	TileViewBase(SDL_Renderer& rend, TileBase& targetTile);
	~TileViewBase();

	void Draw() override;

private:
	TileBase& tile;
};