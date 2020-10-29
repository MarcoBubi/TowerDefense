#pragma once

#include "Tower/TowerBase.h"
#include "Controllers/ProjectileController.h"
#include "Controllers/EnemyController.h"

class SlowTower : public TowerBase
{
public:
	explicit SlowTower(EnemyController* eC, ProjectileController* pC, int x, int y);
	~SlowTower();

};