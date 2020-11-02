#pragma once

#include "Tower/TowerBase.h"

TowerBase::TowerBase(EnemyController* eC, ProjectileController* pC, int x, int y) :
	positionX(x),
	positionY(y),
	enemyController(*eC),
	projectileController(*pC)
{

}

TowerBase::~TowerBase()
{
	delete targetEnemy;
	targetEnemy = nullptr;
}

void TowerBase::TryShoot(float deltaTime)
{
	shootCooldown -= deltaTime;
	if(targetEnemy != nullptr)
	{
		bool targetInRange = IsTargetInRange(targetEnemy);
		if (targetInRange)
		{
			if (IsFacingTarget(targetEnemy))
			{
				if (shootCooldown <= 0.0f) // <= because of float
				{
					Shoot();
				}
			}
			else
			{
				RotateTowardsTarget(targetEnemy);
			}
		}

	}
	else
	{
		FindTarget();
	}

	if (shootCooldown < 0.0f) // <= so it doesn't decrease to infinite
	{
		shootCooldown = 0.0f;
	}
}

void TowerBase::Shoot()
{
	shootCooldown = shootTime;
	projectileController.SpawnProjectile(positionX, positionY, *targetEnemy); 
}

int TowerBase::GetPositionX() const
{
	return positionX;
}

int TowerBase::GetPositionY() const
{
	return positionY;
}

EnemyBase* TowerBase::FindTarget()
{
	for (EnemyBase* enemy : enemyController.GetSpawnedEnemies())
	{
		if (IsTargetInRange(enemy))
		{
			targetEnemy = enemy;
			return targetEnemy; // target first enemy found
		}
	}
	return targetEnemy;
}

bool TowerBase::IsTargetInRange(EnemyBase* enemy)
{
	if (enemy != nullptr)
	{
		float distanceX = enemy->GetPositionX() - positionX;
		float distanceY = enemy->GetPositionY() - positionY;

		float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
		
		if (distance < towerRange)
		{
			targetEnemy = enemy;
			return true;
		}
	}

	return false;
}

void TowerBase::RotateTowardsTarget(EnemyBase* enemy)
{
	float enemyPosX = enemy->GetPositionX();
	float enemyPosY = enemy->GetPositionY();

	float angle = atan2(positionY - enemyPosY, positionX - enemyPosX);
	turretAngle = angle * 180 / Constants::PI;
}

bool TowerBase::IsFacingTarget(EnemyBase* enemy)
{
	// TODO!
	return true;
}
