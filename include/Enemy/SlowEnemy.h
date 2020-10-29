#pragma once

#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"

class SlowEnemy : public EnemyBase
{
public:
	SlowEnemy(EnemyData::EnemyType type, float time);
	~SlowEnemy();

private:
	const int HEALTH = 300;
	const int SPEED = 1;
};