#pragma once

#include "Factories/TowerFactory.h"
#include "Tower/FastTower.h"
#include "Tower/SlowTower.h"

TowerBase* TowerFactory::CreateTower(TowerBase::TowerType type, EnemyController* eC, ProjectileController* pC, int x, int y)
{
	switch (type)
	{
	case TowerBase::TowerType::Slow:
		return new SlowTower(eC, pC, x, y);
		break;
	case TowerBase::TowerType::Fast:
		return new FastTower(eC, pC, x, y);
		break;
	default:
		return nullptr;
		break;
	}
}
