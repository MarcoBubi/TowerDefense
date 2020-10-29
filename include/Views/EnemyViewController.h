#pragma once

#include "SDL.h"
#include "Controllers/EnemyController.h"
#include "Views/EnemyView.h"

class EnemyViewController
{
public:
	explicit EnemyViewController(SDL_Renderer* renderer, EnemyController* enemyController);
	~EnemyViewController();

	void Start();
	void Update(float deltaTime);

private:
	void DrawEnemies();

	int x = 50;
	int y = 50;
	std::vector<EnemyView*> allEnemies;
	std::vector<EnemyView*> spawnedEnemies;
	SDL_Renderer& renderer;
	EnemyController& enemyController;
};