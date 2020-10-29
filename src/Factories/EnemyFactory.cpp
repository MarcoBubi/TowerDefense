#pragma once
#include "Factories/EnemyFactory.h"
#include "Enemy/FastEnemy.h"
#include "Enemy/SlowEnemy.h"

EnemyBase* EnemyFactory::CreateEnemy(EnemyData::EnemyType type, float time, TileController& tC)
{
	switch (type)
	{
	case EnemyData::EnemyType::Fast:
		return new FastEnemy(type, time, tC);
		break;
	case EnemyData::EnemyType::Slow:
		return new SlowEnemy(type, time, tC);
		break;
	default:
		return nullptr;
		break;
	}
}
