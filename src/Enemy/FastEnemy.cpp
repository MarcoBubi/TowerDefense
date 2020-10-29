#pragma once
#include "Enemy/FastEnemy.h"

FastEnemy::FastEnemy(EnemyData::EnemyType type, float time) :
	EnemyBase(time)
{
	health = HEALTH;
	speed = SPEED;
}

FastEnemy::~FastEnemy()
{

}
