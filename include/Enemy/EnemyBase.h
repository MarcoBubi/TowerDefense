#pragma once

class EnemyBase
{
public:
	explicit EnemyBase(float spawnTimer);
	virtual ~EnemyBase();

	void SpawnEnemy(float posX, float posY);

	bool IsSpawned() const;
	float GetSpawnTimer() const;

	float GetHealth();
	float GetPositionX();
	float GetPositionY();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

	void ReceiveDamage(float damage);

protected:
	bool spawned = false;
	float positionX = 50; // spawn point X
	float positionY = 50; // spawn point Y
	float spawnTimer = 0.0f;
	float health = 100.0f;
	float speed = 1.0f;
};