#pragma once

#include "Views/TileViewController.h"
#include "Tiles/TileBase.h"

TileViewController::TileViewController(SDL_Renderer& rend, TileController& tC) :
	ControllerBase(),
	renderer(rend),
	tileController(tC)
{
	int numberOfTiles = tileController.GetNumberOfTiles();
	tileViews = new TileViewBase * [numberOfTiles];
}

TileViewController::~TileViewController()
{

}

void TileViewController::Start()
{
	TileBase** tiles = tileController.GetTiles();
	int tileIndex = 0;

	for (int vert = 0; vert < tileController.GetNumberOfVTiles(); ++vert)
	{
		for (int horz = 0; horz < tileController.GetNumberOfHTiles(); ++horz)
		{
			TileViewBase* tileView = new TileViewBase(renderer, *tiles[tileIndex]);
			tileViewVector.push_back(tileView);
			++tileIndex;
		}
	}
}

void TileViewController::Update(float deltaTime)
{
	for (auto& tile : tileViewVector)
	{
		tile->Draw();
	}

}
