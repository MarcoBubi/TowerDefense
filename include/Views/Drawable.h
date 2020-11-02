#pragma once

#include <SDL.h>

class Drawable
{
public:
	explicit Drawable(SDL_Renderer& rend);
	virtual ~Drawable() = default;

	virtual void Draw() = 0;

protected:
	SDL_Texture* img = nullptr;
	SDL_Renderer& renderer;

	int x = 0;
	int y = 0;
	int w = 50;
	int h = 50;
};