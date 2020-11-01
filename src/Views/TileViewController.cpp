#pragma once

#include "Views/TileViewController.h"
#include "Tiles/TileBase.h"

TileViewController::TileViewController(SDL_Renderer& rend, TileController& tC) :
	renderer(rend),
	tileController(tC)
{

}

TileViewController::~TileViewController()
{

}

void TileViewController::Start()
{

}

void TileViewController::Update(float deltaTime)
{

}
