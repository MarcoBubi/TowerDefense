#pragma once

#include "Controllers/GameController.h"
#include "Factories/EnemyFactory.h"
#include "Factories/ProjectileFactory.h"
#include "Factories/TileFactory.h"
#include "Factories/TowerFactory.h"
#include "SDL.h"
#include <iostream>

GameController::GameController(int screenHeight, int screenWidth) :
	screenH(screenHeight),
	screenW(screenWidth),
	dataLoader(new DataLoader())
{
	InitFactories();

	dataLoader->LoadData();
	player = new Player(*dataLoader->GetPlayerData());
	tileController = new TileController(screenH, screenW, *tileFactory);
	enemyController = new EnemyController(*tileController, *enemyFactory, *player);
	projectileController = new ProjectileController(*enemyController, *tileController, *projectileFactory, *player);
	towerController = new TowerController(*enemyController, *projectileController, *tileController, *towerFactory);
}

GameController::~GameController()
{
	delete projectileController;
	delete enemyController;
	delete towerController;
	delete tileController;

	delete enemyFactory;
	delete projectileFactory;
	delete tileFactory;
	delete towerFactory;
	delete player;

	delete dataLoader;

	projectileController = nullptr;
	enemyController = nullptr;
	towerController = nullptr;
	tileController = nullptr;

	enemyFactory = nullptr;
	projectileFactory = nullptr;
	tileFactory = nullptr;
	towerFactory = nullptr;
	player = nullptr;

	dataLoader = nullptr;
}

void GameController::Start()
{
	tileController->Start();
	tileController->CreateTiles(dataLoader->GetTileData());
	enemyController->CreateEnemies(dataLoader->GetEnemyData());
	enemyController->Start();
	towerController->Start();
}

void GameController::Update(float deltaTime)
{
	enemyController->Update(deltaTime);
	projectileController->Update(deltaTime);
	towerController->Update(deltaTime);
	if (!player->IsAlive())
	{
		EndOfGameReached();
	}
}

ProjectileController& GameController::GetProjectileController()
{
	return *projectileController;
}

TowerController& GameController::GetTowerController()
{
	return *towerController;
}

EnemyController& GameController::GetEnemyController()
{
	return *enemyController;
}

TileController& GameController::GetTileController()
{
	return *tileController;
}

void GameController::TryAddTower(int posX, int posY)
{
	if (buildingMode)
	{
		towerController->TryAddTower(posX, posY);
		buildingMode = !buildingMode;
	}
}

void GameController::SelectTower(TowerBase::TowerType type)
{
	if (buildingMode)
	{
		towerController->SelectTower(type);
	}
}

void GameController::ToggleBuildingMode()
{
	buildingMode = !buildingMode;
}

void GameController::InitFactories()
{
	enemyFactory = new EnemyFactory();
	projectileFactory = new ProjectileFactory();
	tileFactory = new TileFactory();
	towerFactory = new TowerFactory();
}

bool GameController::EndOfGameReached()
{
	// not sure how I want to end the game yet, so I'll leave empty
	std::cout << "End of game reached!" << std::endl;
	return false;
}
