#pragma once

#include "Controllers/TowerController.h"

TowerController::TowerController(EnemyController& eC, ProjectileController& pC, TileController& tC, TowerFactory& tF) :
	enemyController(eC),
	projectileController(pC),
	tileController(tC),
	towerFactory(tF),
	selectedTower(TowerBase::TowerType::Fast)
{

}

TowerController::~TowerController()
{

}

void TowerController::Start()
{

}

void TowerController::Update(float deltaTime)
{
	if (activeTowers.size() > 0)
	{
		for (TowerBase* tower : activeTowers)
		{
			tower->TryShoot(deltaTime);
		}
	}
}

void TowerController::TryAddTower(int posX, int posY)
{
	int x = posX;
	int y = posY;
	if (CanSpawnOnTargetLocation(x, y))
	{
		activeTowers.push_back(towerFactory.CreateTower(selectedTower, &enemyController, &projectileController, x, y));
	}	
}

void TowerController::SelectTower(TowerBase::TowerType type)
{
	selectedTower = type;
}

int TowerController::GetTowerPrice()
{
	return 50; // hardcoded just for testing purpose, will find a better way later
}

std::vector<TowerBase*>& TowerController::GetActiveTowers()
{
	return activeTowers;
}

bool TowerController::CanSpawnOnTargetLocation(int& positionX, int& positionY)
{
	int index = tileController.GetIndexForPosition(positionX, positionY);
	TileBase* targetTile = tileController.GetTileAtIndex(index);

	if (targetTile == nullptr)
	{
		return false;
	}

	positionY = targetTile->GetPositionY();
	positionX = targetTile->GetPositionX();

	return !targetTile->IsPassable();
}

