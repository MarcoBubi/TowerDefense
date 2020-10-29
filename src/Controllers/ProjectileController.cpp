#pragma once

#include "Controllers/ProjectileController.h"
#include <iostream>

ProjectileController::ProjectileController(EnemyController* eC, TileController* tC) :
	enemyController(*eC),
	tileController(*tC),
	projectileFactory(new ProjectileFactory())
{

}

ProjectileController::~ProjectileController()
{
	projectileFactory = nullptr;
}

void ProjectileController::Start()
{

}

void ProjectileController::Update(float deltaTime)
{
	CheckForCollisions();
	DeleteProjectilesOutOfBound();
}

void ProjectileController::SpawnProjectile(int posX, int posY, float angle)
{
	activeProjectiles.push_back(projectileFactory->CreateProjectile());
}

void ProjectileController::CheckForCollisions()
{
	for (EnemyBase* enemy : enemyController.GetSpawnedEnemies())
	{
		for (ProjectileBase* projectile : activeProjectiles)
		{
			if (HaveCollided(projectile, enemy))
			{
				enemyController.GiveDamageToEnemy(projectile->GetProjectileDamage(), enemy);
				DeleteProjectile(projectile);
			}
		}
	}
}

bool ProjectileController::HaveCollided(ProjectileBase* projectile, EnemyBase* enemy)
{
	// Idea: get x, y, width and height of both elements. Get X and Y plus width and height of both
	// check if the coordinates somehow collide, x + width, y + height if it joins x + width and y + height
	// of the other object in the coordinating system .
	return false;
}

void ProjectileController::DeleteProjectile(ProjectileBase* projectile)
{
	for (auto it = activeProjectiles.begin(), itEnd = activeProjectiles.end(); it != itEnd;)
	{
		ProjectileBase* targetProjectile = *it;
		if (targetProjectile == projectile)
		{
			it = activeProjectiles.erase(it);
			std::cout << "Projectile destroyed!" << std::endl;
			itEnd = activeProjectiles.end();
			break;
		}
		else
		{
			++it;
		}
	}
}

void ProjectileController::DeleteProjectilesOutOfBound()
{
	for (ProjectileBase* projectile : activeProjectiles)
	{
		if(tileController.IsPositionOutOfBound(projectile->GetPositionX(), projectile->GetPositionY()))
		{
			DeleteProjectile(projectile);
		}
	}
}

