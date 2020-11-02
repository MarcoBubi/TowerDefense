#pragma once

#include "Views/TowerViewBase.h"

TowerViewBase::TowerViewBase(SDL_Renderer& rend, TowerBase& targetTower) :
	Drawable(rend),
	tower(targetTower)
{

}

TowerViewBase::~TowerViewBase()
{
	delete img;
	img = nullptr;
}

void TowerViewBase::Draw()
{

}
