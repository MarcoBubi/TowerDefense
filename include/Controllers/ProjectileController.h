#pragma once

#include "Factories/ProjectileFactory.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/EnemyController.h"
#include "Controllers/TileController.h"
#include "Player/Player.h"
#include <vector>

class ProjectileBase;

class ProjectileController : public ControllerBase
{
public:
	explicit ProjectileController(EnemyController& eC, TileController& tC, ProjectileFactory& pF, Player& player);
	~ProjectileController();

	void Start() override;
	void Update(float deltaTime) override;

	void SpawnProjectile(int posX, int posY, EnemyBase& enemy);
	const std::vector<ProjectileBase*>& GetActiveProjectiles();
	
private:
	void CheckForCollisions();
	bool HaveCollided(ProjectileBase* projectile, EnemyBase* enemy);
	void DeleteProjectile(ProjectileBase* projectile);
	void DeleteProjectilesOutOfBound();

	EnemyController& enemyController;
	TileController& tileController;
	ProjectileFactory& projectileFactory;
	Player& player;
	std::vector<ProjectileBase*> activeProjectiles;
};