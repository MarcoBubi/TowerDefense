#pragma once

#include "Controllers/ProjectileController.h"
#include "Projectiles/ProjectileBase.h"
#include <iostream>

ProjectileController::ProjectileController(EnemyController& eC, TileController& tC, ProjectileFactory& pF, Player& player) :
	enemyController(eC),
	tileController(tC),
	projectileFactory(pF),
	player(player)
{

}

ProjectileController::~ProjectileController()
{

}

void ProjectileController::Start()
{

}

void ProjectileController::Update(float deltaTime)
{
	for (ProjectileBase* projectile : activeProjectiles)
	{
		projectile->Update(deltaTime);
	}
	CheckForCollisions();
	DeleteProjectilesOutOfBound();
}

void ProjectileController::SpawnProjectile(int posX, int posY, EnemyBase& enemy)
{
	activeProjectiles.push_back(projectileFactory.CreateProjectile(posX, posY, enemy.GetPositionX(), enemy.GetPositionY()));
}

const std::vector<ProjectileBase*>& ProjectileController::GetActiveProjectiles()
{
	return activeProjectiles;
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
	int targetIndex = tileController.GetIndexForPosition(projectile->GetPositionX(), projectile->GetPositionY());

	for (EnemyBase* targetEnemy : enemyController.GetSpawnedEnemies())
	{
		int enemyIndex = tileController.GetIndexForPosition(targetEnemy->GetPositionX(), targetEnemy->GetPositionY());
		if (targetIndex == enemyIndex) // HIT
		{
			targetEnemy->ReceiveDamage(projectile->GetProjectileDamage());
			return true;
		}
	}
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
		int index = tileController.GetIndexForPosition(projectile->GetPositionX(), projectile->GetPositionY());
		TileBase* targetTile = tileController.GetTileAtIndex(index);
		if (targetTile == nullptr)
		{
			// is out of bound!
			DeleteProjectile(projectile);
		}
	}
}

