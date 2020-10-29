#pragma once

#include "Views/EnemyView.h"

EnemyView::EnemyView(SDL_Renderer* renderer, EnemyBase* enemy) : // CREATE AN ENEMY VIEW BASE FOR THIS ALSO, TESTING PURPOSE FOR THE VIEW ONLY
	renderer(*renderer),
	enemy(*enemy)
{
	
}

EnemyView::~EnemyView()
{
	
}

bool EnemyView::CanDraw()
{
	return enemy.IsSpawned();
}

void EnemyView::Draw()
{
	drawn = true;
	img = IMG_LoadTexture(&renderer, IMG_PATH);
	if (img != nullptr)
	{
		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr;
		texr.x = enemy.GetPositionX();
		texr.y = enemy.GetPositionY();
		texr.w = w;
		texr.h = h;

		SDL_RenderCopy(&renderer, img, NULL, &texr);
	}
}
