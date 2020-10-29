#include "Controllers/ViewController.h"

ViewController::ViewController(SDL_Renderer* renderer, GameController* gc) :
	renderer(*renderer),
	gameController(*gc)
{
	enemyViewController = new EnemyViewController(renderer, &gameController.GetEnemyController());
}

void ViewController::Start()
{
	enemyViewController->Start();
}

void ViewController::Update(float deltaTime)
{
	enemyViewController->Update(deltaTime);
}
