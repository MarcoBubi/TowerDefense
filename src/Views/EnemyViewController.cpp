#pragma once

#include "Views/EnemyViewController.h"
#include "Controllers/EnemyController.h"

EnemyViewController::EnemyViewController(SDL_Renderer& rend, EnemyController& enemyController) :
	renderer(rend),
	enemyController(enemyController),
	spawnedEnemies(enemyController.GetSpawnedEnemies())
{
	// DELETE ME, tmp
	img = IMG_LoadTexture(&renderer, IMG_PATH_E1);
}

EnemyViewController::~EnemyViewController()
{
	//delete img;
	//img = nullptr;
	/*for (int i = 0; i < allEnemies.size(); i++)
	{
		delete allEnemies[i];
	}
	allEnemies.clear();

	for (int i = 0; i < spawnedEnemies.size(); i++)
	{
		delete spawnedEnemies[i];
	}
	spawnedEnemies.clear();*/
}

void EnemyViewController::Start()
{
	//for (auto& enemy : enemyController.GetAllEnemies())
	//{
	//	allEnemies.push_back(new EnemyView(renderer, *enemy));
	//}
}

void EnemyViewController::Update(float deltaTime)
{
	DrawEnemies();
}

void EnemyViewController::DrawEnemies()
{
	for (const auto& enemy : spawnedEnemies)
	{
		TmpDrawEnemy(*enemy);
	}
	/*for (EnemyView* enemy : allEnemies)
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
	}*/
}

void EnemyViewController::TmpDrawEnemy(const EnemyBase& enemy)
{
	int w, h;

	if (img != nullptr)
	{
		SDL_QueryTexture(img, NULL, NULL, &w, &h);
		SDL_Rect texr;
		texr.x = enemy.GetPositionX();
		texr.y = enemy.GetPositionY();
		texr.w = w;
		texr.h = h;

		SDL_RenderCopy(&renderer, img, NULL, &texr);
	}
}
