#pragma once

#include "Controllers/GameController.h"
#include "SDL.h"

GameController::GameController(int screenHeight, int screenWidth) :
	screenH(screenHeight),
	screenW(screenWidth),
	dataLoader(new DataLoader()),
	tileController(new TileController(screenH, screenW))
{
	enemyController = new EnemyController(tileController);
	projectileController = new ProjectileController(enemyController, tileController);
	towerController = new TowerController(enemyController, projectileController, tileController);
}

GameController::~GameController()
{
	projectileController = nullptr;
	enemyController = nullptr;
	towerController = nullptr;
	tileController = nullptr;
	dataLoader = nullptr;
}

void GameController::Start()
{
	dataLoader->LoadData();
	player = new Player(*dataLoader->GetPlayerData());
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

bool GameController::EndOfGameReached()
{
	// todo
	return false;
}
