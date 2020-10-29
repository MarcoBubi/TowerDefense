#include "Controllers/ViewController.h"

ViewController::ViewController(SDL_Renderer& rend, GameController& gC) :
	renderer(rend),
	gameController(gC)
{
	enemyViewController = new EnemyViewController(renderer, gameController.GetEnemyController());
}

void ViewController::Start()
{
	enemyViewController->Start();
}

void ViewController::Update(float deltaTime)
{
	enemyViewController->Update(deltaTime);
}
