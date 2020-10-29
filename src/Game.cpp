#include "Game.h"
#include <string>
#include <iostream>

Game::Game()
{

}

Game::~Game()
{
	window = nullptr;
	renderer = nullptr;
	gameController = nullptr;
	viewController = nullptr;

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::string("Error initializing sdl2!");
	}

	window = SDL_CreateWindow
	(
		GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		throw std::string("Could not create window!");
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	gameController = new GameController(SCREEN_HEIGHT, SCREEN_WIDTH);
	gameController->Start();
	viewController = new ViewController(renderer, gameController);
	viewController->Start();
}

void Game::Update(float deltaTime)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		running = false;
	}
	SDL_RenderClear(renderer);
	// game logic
	gameController->Update(deltaTime);
	viewController->Update(deltaTime);
	HandleEvents(event);

	SDL_RenderPresent(renderer);
}

bool Game::IsRunning()
{
	return running;
}

void Game::HandleEvents(SDL_Event event)
{
	switch (event.type)
	{
	case SDL_KEYDOWN:
		KeyPressed(event.key.keysym.sym);
		break;
	case SDL_MOUSEBUTTONDOWN:
		MouseClicked(event.button);
		break;
	default:
		break;
	}
}

void Game::KeyPressed(const SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_b:
		gameController->ToggleBuildingMode();
		break;
	case SDLK_1:
		gameController->SelectTower(TowerBase::TowerType::Fast);
		break;
	case SDLK_2:
		gameController->SelectTower(TowerBase::TowerType::Slow);
		break;
	default:
		break;
	}
}

void Game::MouseClicked(SDL_MouseButtonEvent clickEvent)
{
	int posX = clickEvent.x;
	int posY = clickEvent.y;
	switch (clickEvent.button)
	{
	case SDL_BUTTON_LEFT:
		gameController->TryAddTower(posX, posY);
		break;
	case SDL_BUTTON_RIGHT:
		// ATM DO Nothing
		break;
	default:
		break;
	}
}

