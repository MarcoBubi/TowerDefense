#pragma once

#include "Projectiles/ProjectileBase.h"
#include "Projectiles/NormalProjectile.h"

NormalProjectile::NormalProjectile(int posX, int posY, int xTarget, int yTarget) :
	ProjectileBase(posX, posY, xTarget, yTarget)
{

}

NormalProjectile::~NormalProjectile()
{

}
