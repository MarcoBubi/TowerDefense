#pragma once

#include "Factories/EnemyFactory.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/TileController.h"
#include <vector>

class EnemyController : public ControllerBase
{
public:
	EnemyController(TileController& tC, EnemyFactory& eF);
	~EnemyController();

	void Start() override;
	void Update(float deltaTime) override;

	void CreateEnemies(std::vector<EnemyData*> enemiesData);
	void TrySpawnEnemies();
	bool TrySpawnEnemy(EnemyBase& enemy);
	void GiveDamageToEnemy(float damage, EnemyBase* enemy);

	std::vector<EnemyBase*> GetAllEnemies() const;
	std::vector<EnemyBase*> GetSpawnedEnemies() const;

private:
	void DeleteEnemy(EnemyBase* enemy);

	float timer = 0.0f;
	TileController& tileController;
	EnemyFactory& enemyFactory;
	std::vector<EnemyBase*> allEnemies;
	std::vector<EnemyBase*> availableEnemies;
	std::vector<EnemyBase*> spawnedEnemies;
};