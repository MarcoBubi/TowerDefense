#pragma once

#include "Views/TileViewBase.h"

TileViewBase::TileViewBase(SDL_Renderer& rend, TileBase& targetTile) :
	Drawable(rend),
	tile(targetTile)
{
	if (tile.IsPassable())
	{
		img = IMG_LoadTexture(&renderer, IMG_PATH_T2);
	}
	else
	{
		img = IMG_LoadTexture(&renderer, IMG_PATH_T1);
	}
}

TileViewBase::~TileViewBase()
{
	delete img;
	img = nullptr;
}

void TileViewBase::Draw()
{
	if (img != nullptr)
	{
		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr;
		texr.x = tile.GetPositionX();
		texr.y = tile.GetPositionY();
		texr.w = w;
		texr.h = h;

		SDL_RenderCopy(&renderer, img, NULL, &texr);
	}
}
