#pragma once

// MOVE THIS TO VIEWS, somehow it got ported here
#include "SDL.h"
#include "GameController.h"
#include "Controllers/ControllerBase.h"
#include "Views/EnemyViewController.h"
#include "Views/TileViewController.h"
#include "Views/TowerViewController.h"
#include "Views/ProjectileViewController.h"

class ViewController : public ControllerBase // This should be moved in the Views folder
{
public:
	explicit ViewController(SDL_Renderer& rend, GameController& gC);
	~ViewController();

	void Start() override;
	void Update(float deltaTime) override;

private:
	EnemyViewController* enemyViewController;
	TileViewController* tileViewController;
	TowerViewController* towerViewController;
	ProjectileViewController* projectileViewController;
	SDL_Renderer& renderer;
	GameController& gameController;
};