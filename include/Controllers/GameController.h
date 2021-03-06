#pragma once

#include "Controllers/ControllerBase.h"
#include "Controllers/EnemyController.h"
#include "Controllers/TowerController.h"
#include "Controllers/TileController.h"
#include "Controllers/ProjectileController.h"
#include "Loaders/DataLoader.h"
#include "Player/Player.h"
#include <vector>

class EnemyFactory;
class ProjectileFactory;
class TileFactory;
class TowerFactory;

class GameController : public ControllerBase
{
public:
	GameController(int screenHeight, int screenWidth);
	~GameController();

	void Start() override;
	void Update(float deltaTime) override;

	ProjectileController& GetProjectileController();
	TowerController& GetTowerController();
	EnemyController& GetEnemyController();
	TileController& GetTileController();
	
	void TryAddTower(int posX, int posY);
	void SelectTower(TowerBase::TowerType type);

	void ToggleBuildingMode();

private:
	void InitFactories();
	bool EndOfGameReached();

	int screenH;
	int screenW;
	bool buildingMode = false;
	ProjectileController* projectileController = nullptr;
	TowerController* towerController = nullptr;
	EnemyController* enemyController = nullptr;
	TileController* tileController = nullptr;
	EnemyFactory* enemyFactory = nullptr;
	ProjectileFactory* projectileFactory = nullptr;
	TileFactory* tileFactory = nullptr;
	TowerFactory* towerFactory = nullptr;
	DataLoader* dataLoader = nullptr;
	Player* player = nullptr;
};
