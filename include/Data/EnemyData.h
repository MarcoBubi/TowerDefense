#pragma once

struct EnemyData
{
	enum class EnemyType
	{
		Fast = 1,
		Slow = 2
	};

	EnemyType enemyType;
	float spawnTime;

	EnemyData(EnemyType type, float time);
};