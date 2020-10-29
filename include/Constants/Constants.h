#pragma once

#include <SDL.h>
#include <string>

struct Constants
{
	// Keyboard inputs
	static const SDL_Keycode KEY_B;
	static const SDL_Keycode KEY_Q;

	// Game Data

	static const int GAME_FIELD_OFFSET_X = 15;
	static const int GAME_FIELD_OFFSET_Y = 10;
	static const int TILE_SIZE = 50;
	static constexpr float PI = 3.141592;
};
