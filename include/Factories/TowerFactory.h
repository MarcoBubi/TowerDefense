#pragma once

#include "Tower/TowerBase.h"
#include "Controllers/ProjectileController.h"
#include "Controllers/EnemyController.h"

class TowerFactory
{
public:
	TowerBase* CreateTower(TowerBase::TowerType type, EnemyController* eC, ProjectileController* pC, int x, int y);

};