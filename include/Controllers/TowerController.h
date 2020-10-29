#pragma once

#include "Factories/TowerFactory.h"
#include "Tower/TowerBase.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/ProjectileController.h"
#include "Controllers/EnemyController.h"
#include "Controllers/TileController.h"
#include <vector>

class TowerController : public ControllerBase
{
public:
	TowerController(EnemyController* eC, ProjectileController* pC, TileController* tC);
	~TowerController();

	void Start() override;
	void Update(float deltaTime) override;

	void TryAddTower(int posX, int posY);
	void SelectTower(TowerBase::TowerType type);
	int GetTowerPrice();

private:
	bool CanSpawnOnTargetLocation(int positionX, int positionY);

	TileController& tileController;
	EnemyController& enemyController;
	ProjectileController& projectileController;
	TowerBase::TowerType selectedTower;
	TowerFactory* towerFactory = nullptr;
	std::vector<TowerBase*> activeTowers;
};