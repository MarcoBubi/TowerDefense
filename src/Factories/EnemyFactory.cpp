#pragma once
#include "Factories/EnemyFactory.h"
#include "Enemy/FastEnemy.h"
#include "Enemy/SlowEnemy.h"

EnemyBase* EnemyFactory::CreateEnemy(EnemyData::EnemyType type, float time)
{
	switch (type)
	{
	case EnemyData::EnemyType::Fast:
		return new FastEnemy(type, time);
		break;
	case EnemyData::EnemyType::Slow:
		return new SlowEnemy(type, time);
		break;
	default:
		return nullptr;
		break;
	}
}
