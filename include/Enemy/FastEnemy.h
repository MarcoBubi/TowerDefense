#pragma once

#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"

class FastEnemy : public EnemyBase
{
public:
	FastEnemy(EnemyData::EnemyType type, float time);
	~FastEnemy();

private:
	const int HEALTH = 100;
	const int SPEED = 2;
};
