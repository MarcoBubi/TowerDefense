#pragma once

#include "Projectiles/ProjectileBase.h"
#include "Factories/ProjectileFactory.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/EnemyController.h"
#include "Controllers/TileController.h"
#include <vector>

class ProjectileController : public ControllerBase
{
public:
	explicit ProjectileController(EnemyController* eC, TileController* tC);
	~ProjectileController();

	void Start() override;
	void Update(float deltaTime) override;

	void SpawnProjectile(int posX, int posY, float angle);
	
private:
	void CheckForCollisions();
	bool HaveCollided(ProjectileBase* projectile, EnemyBase* enemy);
	void DeleteProjectile(ProjectileBase* projectile);
	void DeleteProjectilesOutOfBound();

	EnemyController& enemyController;
	TileController& tileController;
	ProjectileFactory* projectileFactory = nullptr; 
	std::vector<ProjectileBase*> activeProjectiles;
};