#pragma once

#include "Enemy/EnemyBase.h"
#include <SDL.h>
#include <SDL_image.h>

#define IMG_PATH "resources/enemy_1.png"

class EnemyView
{
public:
	explicit EnemyView(SDL_Renderer* renderer, EnemyBase* enemy);
	~EnemyView();

	bool CanDraw();
	void Draw();

private:
	SDL_Renderer& renderer;
	SDL_Texture* img = nullptr;
	int x = 100;
	int y = 100;
	int w = 50;
	int h = 50;
	bool drawn = false;
	EnemyBase& enemy;

};