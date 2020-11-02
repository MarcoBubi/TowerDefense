#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Controllers/ControllerBase.h"
#include "Controllers/EnemyController.h"
#include "Views/EnemyView.h"

#define IMG_PATH_E1 "resources/enemy_1.png"
#define IMG_PATH_E2 "resources/enemy_2.png" // this will be in it's own enemy view

class EnemyViewController : public ControllerBase
{
public:
	explicit EnemyViewController(SDL_Renderer& rend, EnemyController& enemyController);
	~EnemyViewController();

	void Start() override;
	void Update(float deltaTime) override;

private:
	void DrawEnemies();
	void TmpDrawEnemy(const EnemyBase& enemy);

	const std::vector<EnemyBase*>& spawnedEnemies;
	SDL_Renderer& renderer;
	EnemyController& enemyController;

	SDL_Texture* img; // remove this later, just tmp for view spawning till I found out a better solution
};