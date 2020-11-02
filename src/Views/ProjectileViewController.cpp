#pragma once

#include "Views/ProjectileViewController.h"

ProjectileViewController::ProjectileViewController(SDL_Renderer& rend, ProjectileController& pC) :
	ControllerBase(),
	renderer(rend),
	projectileController(pC),
	spawnedProjectiles(projectileController.GetActiveProjectiles())
{	
	// DELETE ME, tmp
	img = IMG_LoadTexture(&renderer, IMG_PATH_PROJECTILE1);
}

ProjectileViewController::~ProjectileViewController()
{

}

void ProjectileViewController::Start()
{

}

void ProjectileViewController::Update(float deltaTime)
{
	for (ProjectileBase* projectile : spawnedProjectiles)
	{
		TmpDraw(projectile);
	}
}

void ProjectileViewController::TmpDraw(ProjectileBase* projectile)
{
	int w, h;

	if (img != nullptr)
	{
		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr;
		texr.x = projectile->GetPositionX();
		texr.y = projectile->GetPositionY();
		texr.w = w;
		texr.h = h;

		SDL_RenderCopy(&renderer, img, NULL, &texr);
	}
}
