#pragma once

#include "Drawable.h"
#include "Tower/TowerBase.h"
#include <SDL.h>

class TowerViewBase : public Drawable
{
public:
	TowerViewBase(SDL_Renderer& rend, TowerBase& targetTower);
	~TowerViewBase();

	void Draw() override;

private:
	TowerBase& tower;
};
