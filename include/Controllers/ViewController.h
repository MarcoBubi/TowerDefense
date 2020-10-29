#pragma once

#include "SDL.h"
#include "GameController.h"
#include "Controllers/ControllerBase.h"
#include "Views/EnemyViewController.h"

class ViewController : public ControllerBase// This should be moved in the Views folder
{
public:
	explicit ViewController(SDL_Renderer& rend, GameController& gC);

	void Start() override;
	void Update(float deltaTime) override;

private:
	EnemyViewController* enemyViewController;
	SDL_Renderer& renderer;
	GameController& gameController;
};