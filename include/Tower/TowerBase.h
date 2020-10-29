#pragma once

#include "Enemy/EnemyBase.h"
#include "Controllers/ProjectileController.h"
#include "Controllers/EnemyController.h"
#include "Constants/Constants.h"

class TowerBase
{
public:
	enum class TowerType
	{
		Slow = 1,
		Fast = 2
	};

public:
	explicit TowerBase(EnemyController* eC, ProjectileController* pC, int x, int y);
	virtual ~TowerBase();

	void TryShoot(float deltaTime);
	void Shoot();
	int GetPositionX() const;
	int GetPositionY() const;

protected:
	EnemyBase* FindTarget();
	bool IsTargetInRange(EnemyBase* enemy);
	void RotateTowardsTarget(EnemyBase* enemy);
	bool IsFacingTarget(EnemyBase* enemy);

protected:
	EnemyController& enemyController;
	ProjectileController& projectileController;
	EnemyBase* targetEnemy = nullptr;
	int positionX = 0;
	int positionY = 0;
	float towerRange = 5 * Constants::TILE_SIZE;
	float shootCooldown = 5.0f;
	float shootTimer = 0.0f;
	float turretAngle = 0.0f;
	int towerPrice = 50;
};