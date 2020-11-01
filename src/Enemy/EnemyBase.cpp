#pragma once

#include "Enemy/EnemyBase.h"
#include "PathFinding/PathNode.h"

EnemyBase::EnemyBase(float spawnTimer, TileController& tC) :
    tileController(tC),
    spawnTimer(spawnTimer),
    destinationPoint(nullptr),
    spawnPoint(nullptr),
    currentPoint(nullptr)
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

        if (pathFinder->IsPathFound())
        {
            enemyNodeIndex = 0;
        }
    }
    else if(pathFinder->IsPathFound() && enemyNodeIndex > -1)
    {
        PathNode* pathNode = pathFinder->GetNodeAtIndex(enemyNodeIndex);
        TileBase* targetTile = pathNode != nullptr ? pathNode->GetTile() : nullptr;
        
        if (targetTile != nullptr)
        {
            float targetX = targetTile->GetPositionX();
            float targetY = targetTile->GetPositionY();
            MoveToTarget(targetX, targetY);

            if (positionX == targetX && positionY == targetY)
            {
                ++enemyNodeIndex;
                currentPoint->SetPath(false);
                currentPoint = targetTile;

                enemyNodeIndex = -1; // can search for new node
                pathFinder->Reset();
                pathFinder->FindPath(currentPoint, destinationPoint);
            }
        }
    }
}

void EnemyBase::SpawnEnemy(TileBase& spawnTile, TileBase& destinationTile)
{
    spawnPoint = &spawnTile;
    currentPoint = spawnPoint;
    destinationPoint = &destinationTile;
    spawned = true;

    positionX = spawnTile.GetPositionX();
    positionY = spawnTile.GetPositionY();

    pathFinder->FindPath(spawnPoint, destinationPoint);
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

bool EnemyBase::IsTargetReached()
{
    return pathFinder->IsPathReached();
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

void EnemyBase::ReceiveDamage(float damage)
{
    health -= damage;
}

void EnemyBase::MoveToTarget(int targetX, int targetY)
{
    MoveToTargetHorizontally(targetX);
    MoveToTargetVertically(targetY);
}

void EnemyBase::MoveToTargetHorizontally(int targetX)
{
    if (targetX > positionX)
    {
        positionX += speed;
    }
    else if(targetX < positionX)
    {
        positionX -= speed;
    }
    else
    {
        return;
    }
}

void EnemyBase::MoveToTargetVertically(int targetY)
{
    if (targetY > positionY)
    {
        positionY += speed;
    }
    else if(targetY < positionY)
    {
        positionY -= speed;
    }
    else
    {
        return;
    }
}
