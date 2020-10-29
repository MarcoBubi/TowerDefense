#pragma once

#include "Tower/TowerBase.h"
#include "Controllers/ProjectileController.h"
#include "Controllers/EnemyController.h"

class FastTower : public TowerBase
{
public:
	explicit FastTower(EnemyController* eC, ProjectileController* pC, int x, int y);
	~FastTower();

};