#pragma once

#include "SDL.h"
#include "Controllers/TileController.h"

class TileViewController
{
public:
	TileViewController(SDL_Renderer& rend, TileController& tC);
	~TileViewController();
	
	void Start();
	void Update(float deltaTime);

private:
	SDL_Renderer& renderer;
	TileController& tileController;
};
