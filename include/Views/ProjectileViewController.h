#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/ProjectileController.h"

#define IMG_PATH_PROJECTILE1 "resources/projectile_1.png" // other view

class ProjectileViewController : public ControllerBase
{
public:
	ProjectileViewController(SDL_Renderer& rend, ProjectileController& pC);
	~ProjectileViewController();

	void Start() override;
	void Update(float deltaTime) override;

private:
	void TmpDraw(ProjectileBase* projectile);

	SDL_Renderer& renderer;
	ProjectileController& projectileController;
	const std::vector<ProjectileBase*>& spawnedProjectiles;

	SDL_Texture* img; // remove this later, just tmp for view spawning till I found out a better solution
};