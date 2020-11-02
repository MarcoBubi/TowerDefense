#pragma once

#include "Enemy/EnemyBase.h"
#include "Drawable.h"
#include <SDL.h>
#include <SDL_image.h>

#define IMG_PATH_E1 "resources/enemy_1.png"
#define IMG_PATH_E2 "resources/enemy_2.png" // this will be in it's own enemy view

class EnemyView : public Drawable
{
public:
	explicit EnemyView(SDL_Renderer& renderer, EnemyBase& enemy);
	~EnemyView();

	bool CanDraw();
	void Draw();

private:
	EnemyBase& enemy;
};