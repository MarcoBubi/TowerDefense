#pragma once

#include "Enemy/SlowEnemy.h"

SlowEnemy::SlowEnemy(EnemyData::EnemyType type, float time) :
	EnemyBase(time)
{
	health = 250.0f;
}

SlowEnemy::~SlowEnemy()
{

}
