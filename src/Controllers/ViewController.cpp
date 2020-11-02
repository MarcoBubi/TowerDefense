#pragma once

#include "Controllers/ViewController.h"

ViewController::ViewController(SDL_Renderer& rend, GameController& gC) :
	renderer(rend),
	gameController(gC)
{
	tileViewController = new TileViewController(renderer, gameController.GetTileController());
	enemyViewController = new EnemyViewController(renderer, gameController.GetEnemyController());
	towerViewController = new TowerViewController(renderer, gameController.GetTowerController());
	projectileViewController = new ProjectileViewController(renderer, gameController.GetProjectileController());
}

ViewController::~ViewController()
{
	delete enemyViewController;
	enemyViewController = nullptr;
	delete tileViewController;
	tileViewController = nullptr;
	delete towerViewController;
	towerViewController = nullptr;
	delete projectileViewController;
	projectileViewController = nullptr;
}

void ViewController::Start()
{
	tileViewController->Start();
	enemyViewController->Start();
	towerViewController->Start();
	projectileViewController->Start();
}

void ViewController::Update(float deltaTime)
{
	tileViewController->Update(deltaTime);
	enemyViewController->Update(deltaTime);
	towerViewController->Update(deltaTime);
	projectileViewController->Update(deltaTime);
}
