#pragma once

#include "Projectiles/ProjectileBase.h"
#include <math.h>

ProjectileBase::ProjectileBase()
{

}

ProjectileBase::~ProjectileBase()
{

}

void ProjectileBase::Update(float deltaTime)
{
    positionX += speed * cosf(angle) * deltaTime;
    positionY += speed * sinf(angle) * deltaTime;
}

float ProjectileBase::GetProjectileDamage() const
{
    return damage;
}

int ProjectileBase::GetPositionX() const
{
    return positionX;
}

int ProjectileBase::GetPositionY() const
{
    return positionY;
}

float ProjectileBase::GetSpeed() const
{
    return speed;
}

float ProjectileBase::GetAngle() const
{
    return angle;
}
