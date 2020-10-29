#pragma once

#include "Controllers/TileController.h"
#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"

class FastEnemy : public EnemyBase
{
public:
	FastEnemy(EnemyData::EnemyType type, float time, TileController& tC);
	~FastEnemy();

private:
	const int HEALTH = 100;
	const int SPEED = 2;
};
