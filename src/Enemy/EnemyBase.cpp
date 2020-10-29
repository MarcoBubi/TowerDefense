#pragma once

#include "Enemy/EnemyBase.h"

EnemyBase::EnemyBase(float spawnTimer) :
    spawnTimer(spawnTimer)
{

}

EnemyBase::~EnemyBase()
{

}

void EnemyBase::SpawnEnemy(float posX, float posY)
{
    positionX = posX;
    positionY = posY;
    spawned = true;
}

bool EnemyBase::IsSpawned() const
{
    return spawned;
}

float EnemyBase::GetSpawnTimer() const
{
    return spawnTimer;
}

float EnemyBase::GetHealth()
{
    return health;
}

float EnemyBase::GetPositionX()
{
    return positionX;
}

float EnemyBase::GetPositionY()
{
    return positionY;
}

void EnemyBase::MoveRight()
{
    positionX += speed;
}

void EnemyBase::MoveLeft()
{
    positionX -= speed;
}

void EnemyBase::MoveUp()
{
    positionY -= speed;
}

void EnemyBase::MoveDown()
{
    positionY += speed;
}

void EnemyBase::ReceiveDamage(float damage)
{
    health -= damage;
}
