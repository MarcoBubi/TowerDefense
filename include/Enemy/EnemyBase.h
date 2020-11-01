#pragma once

#include "Controllers/TileController.h"
#include "PathFinding/PathFinding.h"

class EnemyBase
{
public:
	explicit EnemyBase(float spawnTimer, TileController& tC);
	virtual ~EnemyBase();

	void Update(float deltaTime);

	void SpawnEnemy(TileBase& spawnTile, TileBase& destinationTile);
	void SetDestinationPoint(TileBase& destinationTile);
	void SetSpawnPoint(TileBase& spawnTile);

	bool IsSpawned() const;
	bool IsTargetReached();
	float GetSpawnTimer() const;

	float GetHealth();
	float GetPositionX();
	float GetPositionY();

	void ReceiveDamage(float damage);

protected:
	void MoveToTarget(int targetX, int targetY);
	void MoveToTargetHorizontally(int targetX);
	void MoveToTargetVertically(int targetY);

	bool spawned = false;
	int enemyNodeIndex = -1; // starting value for pathfinding
	float positionX = 0.0f; 
	float positionY = 0.0f; 
	float spawnTimer = 0.0f;
	float health = 100.0f;
	float speed = 0.6f;

	PathFinding* pathFinder;
	TileController& tileController;
	TileBase* destinationPoint;
	TileBase* spawnPoint;
	TileBase* currentPoint;
};