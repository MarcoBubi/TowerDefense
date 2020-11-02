#pragma once

#include "Projectiles/ProjectileBase.h"

class ProjectileFactory
{
public:
	ProjectileBase* CreateProjectile(int posX, int posY, int targetX, int targetY);

};