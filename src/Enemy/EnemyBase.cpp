#pragma once

#include "Enemy/EnemyBase.h"

EnemyBase::EnemyBase(float spawnTimer, TileController& tC) :
    tileController(tC),
    spawnTimer(spawnTimer),
    destinationPoint(nullptr),
    spawnPoint(nullptr)
{
    pathFinder = new PathFinding(tileController);
}

EnemyBase::~EnemyBase()
{

}

void EnemyBase::Update(float deltaTime)
{
    if (pathFinder->IsPathSearching())
    {
        pathFinder->Update(deltaTime);
    }
}

void EnemyBase::SpawnEnemy()
{
    positionX = spawnPoint->GetPositionX();
    positionY = spawnPoint->GetPositionY();
    spawned = true;
}

void EnemyBase::SetDestinationPoint(TileBase& destinationTile)
{
    destinationPoint = &destinationTile;
}

void EnemyBase::SetSpawnPoint(TileBase& spawnTile)
{
    spawnPoint = &spawnTile;
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

void EnemyBase::FindPath()
{

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
