#pragma once
#include "Enemy/FastEnemy.h"

FastEnemy::FastEnemy(EnemyData::EnemyType type, float time, TileController& tC) :
	EnemyBase(time, tC)
{
	health = HEALTH;
	speed = SPEED;
}

FastEnemy::~FastEnemy()
{

}
