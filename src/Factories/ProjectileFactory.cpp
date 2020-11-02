#pragma once

#include "Factories/ProjectileFactory.h"
#include "Projectiles/NormalProjectile.h"

ProjectileBase* ProjectileFactory::CreateProjectile(int posX, int posY, int targetX, int targetY)
{
    return new NormalProjectile(posX, posY, targetX, targetY);
}
