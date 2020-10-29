#pragma once

#include "Controllers/GameController.h"
#include "Controllers/ViewController.h"
#include <SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define GAME_TITLE "Tower Defense"

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update(float deltaTime);
	bool IsRunning();

private:
	void HandleEvents(SDL_Event event);
	void KeyPressed(const SDL_Keycode key);
	void MouseClicked(SDL_MouseButtonEvent clickEvent);

	bool running = true;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	GameController* gameController = nullptr;
	ViewController* viewController = nullptr;
};