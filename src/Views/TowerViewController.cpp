#pragma once

#include "Views/TowerViewController.h"

TowerViewController::TowerViewController(SDL_Renderer& rend, TowerController& tC) :
	renderer(rend),
	towerController(tC)
{
	// remove this, just tmp
	img = IMG_LoadTexture(&renderer, IMG_PATH_Tower1);
}

TowerViewController::~TowerViewController()
{
	//delete img;
	//img = nullptr;
	//for (auto& entry : towerViews)
	//{
	//	delete entry;
	//}
	//towerViews.clear();
}

void TowerViewController::Start()
{
	//for (TowerBase* tower : towerController.GetActiveTowers())
	//{
	//	towerViews.push_back(new TowerViewBase(renderer, *tower));
	//}
}

void TowerViewController::Update(float deltaTime)
{
	//for (TowerViewBase* tower : towerViews)
	//{
	//	tower->Draw();
	//}

	for (TowerBase* tower : towerController.GetActiveTowers())
	{
		TmpDraw(tower);
	}
}

void TowerViewController::TmpDraw(TowerBase* tower)
{
	int w, h;

	if (img != nullptr)
	{
		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr;
		texr.x = tower->GetPositionX();
		texr.y = tower->GetPositionY();
		texr.w = w;
		texr.h = h;

		SDL_RenderCopy(&renderer, img, NULL, &texr);
	}
}

