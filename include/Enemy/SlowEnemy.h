#pragma once

#include "Controllers/TileController.h"
#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"

class SlowEnemy : public EnemyBase
{
public:
	SlowEnemy(EnemyData::EnemyType type, float time, TileController& tC);
	~SlowEnemy();

private:
	const int HEALTH = 300;
	const int SPEED = 1;
};