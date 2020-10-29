#pragma once

#include "Controllers/TileController.h"
#include "PathFinding/PathFinding.h"

class EnemyBase
{
public:
	explicit EnemyBase(float spawnTimer, TileController& tC);
	virtual ~EnemyBase();

	void Update(float deltaTime);

	void SpawnEnemy();
	void SetDestinationPoint(TileBase& destinationTile);
	void SetSpawnPoint(TileBase& spawnTile);

	bool IsSpawned() const;
	float GetSpawnTimer() const;

	float GetHealth();
	float GetPositionX();
	float GetPositionY();

	void ReceiveDamage(float damage);

protected:
	void FindPath();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	bool spawned = false;
	float positionX = 50; // spawn point X
	float positionY = 50; // spawn point Y
	float spawnTimer = 0.0f;
	float health = 100.0f;
	float speed = 1.0f;

	PathFinding* pathFinder;
	TileController& tileController;
	TileBase* destinationPoint;
	TileBase* spawnPoint;
};