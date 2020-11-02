#pragma once

#include "Projectiles/ProjectileBase.h"

class NormalProjectile : public ProjectileBase
{
public:
	NormalProjectile(int posX, int posY, int xTarget, int yTarget);
	~NormalProjectile();

};
