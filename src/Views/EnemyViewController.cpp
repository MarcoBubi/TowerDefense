#pragma once

#include "Views/EnemyViewController.h"
#include "Controllers/EnemyController.h"

EnemyViewController::EnemyViewController(SDL_Renderer& rend, EnemyController& enemyController) :
	renderer(rend),
	enemyController(enemyController)
{

}

EnemyViewController::~EnemyViewController()
{

}

void EnemyViewController::Start()
{
	for (auto& enemy : enemyController.GetAllEnemies())
	{
		allEnemies.push_back(new EnemyView(&renderer, enemy));
	}
}

void EnemyViewController::Update(float deltaTime)
{
	DrawEnemies();
}

void EnemyViewController::DrawEnemies()
{
	for (EnemyView* enemy : allEnemies)
	{
		if (enemy->CanDraw())
		{
			for (auto it = allEnemies.begin(), itEnd = allEnemies.end(); it != itEnd;)
			{
				EnemyView* targetEnemy = *it;
				if (targetEnemy == enemy)
				{
					spawnedEnemies.push_back(*it);
					it = allEnemies.erase(it);
					itEnd = allEnemies.end();
					break;
				}
				else
				{
					++it;
				}
			}
		}
	}

	for (EnemyView* enemy : spawnedEnemies)
	{
		enemy->Draw();
	}
}
