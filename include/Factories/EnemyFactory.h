#pragma once

#include "Controllers/TileController.h"
#include "Data/EnemyData.h"
#include "Enemy/EnemyBase.h"

class EnemyFactory
{
public:
	EnemyBase* CreateEnemy(EnemyData::EnemyType type, float time, TileController& tC);

};