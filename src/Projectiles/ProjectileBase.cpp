#pragma once

#include "Projectiles/ProjectileBase.h"
#include "Constants/Constants.h"

ProjectileBase::ProjectileBase(int x, int y, int targetX, int targetY) :
    positionX(x),
    positionY(y),
    targetX(targetX),
    targetY(targetY)
{
    SetAngle();
    CalculateMovement();
}

ProjectileBase::~ProjectileBase()
{

}

void ProjectileBase::Update(float deltaTime)
{
    positionX += movementX;
    positionY += movementY;
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

void ProjectileBase::SetAngle()
{
    float pathX = targetX - positionX;
    float pathY = targetY - positionY;
    float angleDegree = atan2f(pathY, pathX) * 180 / Constants::PI;
    angle = angleDegree * (Constants::PI / 180.0f);
}

void ProjectileBase::CalculateMovement()
{
    if (targetX > positionX)
    {
        movementX = speed * cosf(angle);
    }
    else
    {
        movementX = speed * cosf(angle);
    }

    if (targetY > positionY)
    {
        movementY = speed * sinf(angle);
    }
    else if (targetY < positionY)
    {
        movementY = speed * sinf(angle);
    }
}
