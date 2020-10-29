#pragma once

#include "Factories/ProjectileFactory.h"
#include "Projectiles/NormalProjectile.h"

ProjectileBase* ProjectileFactory::CreateProjectile()
{
    return new NormalProjectile();
}
