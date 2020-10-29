#pragma once

#include "Enemy/SlowEnemy.h"

SlowEnemy::SlowEnemy(EnemyData::EnemyType type, float time, TileController& tC) :
	EnemyBase(time, tC)
{
	health = HEALTH;
}

SlowEnemy::~SlowEnemy()
{

}
