#pragma once

#include "Enemy/EnemyBase.h"
#include "Data/EnemyData.h"

class EnemyFactory
{
public:
	EnemyBase* CreateEnemy(EnemyData::EnemyType type, float time);

};