#pragma once

#include "SDL.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/TileController.h"
#include "Views/TileViewBase.h"
#include <vector>

#define IMG_PATH_T1 "resources/impassable_1.png"
#define IMG_PATH_T2 "resources/passable_1.png"

class TileViewController : public ControllerBase
{
public:
	TileViewController(SDL_Renderer& rend, TileController& tC);
	~TileViewController();
	
	void Start() override;
	void Update(float deltaTime) override;

private:
	SDL_Renderer& renderer;
	TileController& tileController;
	TileViewBase** tileViews;
	std::vector<TileViewBase*> tileViewVector;
};
