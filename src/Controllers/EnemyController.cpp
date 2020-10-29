#pragma once

#include "Controllers/EnemyController.h"
#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"
#include <iostream>

EnemyController::EnemyController(TileController& tC, EnemyFactory& eF) :
	tileController(tC),
	enemyFactory(eF)
{

}

EnemyController::~EnemyController()
{
	allEnemies.clear();
	spawnedEnemies.clear();
}

void EnemyController::Start()
{
	availableEnemies = allEnemies;
}

void EnemyController::Update(float deltaTime)
{
	timer += deltaTime;
	TrySpawnEnemies();
	for (auto& enemy : spawnedEnemies)
	{
		enemy->Update(deltaTime);
	}
}

void EnemyController::CreateEnemies(std::vector<EnemyData*> enemiesData)
{
	for (auto enemy : enemiesData)
	{
		allEnemies.push_back(enemyFactory.CreateEnemy(enemy->enemyType, enemy->spawnTime, tileController));
	}
}

void EnemyController::TrySpawnEnemies()
{
	for (auto& enemy : availableEnemies)
	{
		bool enemySpawned = TrySpawnEnemy(*enemy);

		if (enemySpawned)
		{
			for (auto it = availableEnemies.begin(), itEnd = availableEnemies.end(); it != itEnd;)
			{
				EnemyBase* targetEnemy = *it;
				if (targetEnemy == enemy)
				{
					spawnedEnemies.push_back(*it);
					it = availableEnemies.erase(it);
					std::cout << "Enemy added to spawned list!" << std::endl;
					itEnd = availableEnemies.end();
					break;
				}
				else
				{
					++it;
				}
			}
		}
	}
}

bool EnemyController::TrySpawnEnemy(EnemyBase& enemy)
{
	if (timer >= enemy.GetSpawnTimer() && !enemy.IsSpawned())
	{
		TileBase& spawnPoint = tileController.GetRandomSpawnPoint(); 
		enemy.SetSpawnPoint(spawnPoint);

		TileBase& destinationPoint = tileController.GetRandomPlayerPoint();
		enemy.SetDestinationPoint(destinationPoint);
		
		enemy.SpawnEnemy();
		std::cout << "Enemy spawned!" << std::endl;

		return true;
	}
	return false;
}

void EnemyController::GiveDamageToEnemy(float damage, EnemyBase* enemy)
{
	enemy->ReceiveDamage(damage);
}

std::vector<EnemyBase*> EnemyController::GetAllEnemies() const
{
	return allEnemies;
}

std::vector<EnemyBase*> EnemyController::GetSpawnedEnemies() const
{
	return spawnedEnemies;
}

void EnemyController::DeleteEnemy(EnemyBase* enemy)
{
	for (auto it = spawnedEnemies.begin(), itEnd = spawnedEnemies.end(); it != itEnd;)
	{
		EnemyBase* targetEnemy = *it;
		if (targetEnemy == enemy)
		{
			it = spawnedEnemies.erase(it);
			std::cout << "Enemy deleted from spawned list!" << std::endl;
			itEnd = spawnedEnemies.end();
			break;
		}
		else
		{
			++it;
		}
	}
}
