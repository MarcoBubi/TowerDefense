#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/TowerController.h"
#include "Views/TowerViewBase.h"

#define IMG_PATH_Tower1 "resources/tower_1.png"

class TowerViewController : public ControllerBase
{
public:
	TowerViewController(SDL_Renderer& rend, TowerController& tC);
	~TowerViewController();

	void Start() override;
	void Update(float deltaTime) override;
	
private:
	void TmpDraw(TowerBase* tower);

	TowerController& towerController;
	SDL_Renderer& renderer;
	std::vector<TowerViewBase*> towerViews;

	SDL_Texture* img; // REMOVE ME! tmp
};