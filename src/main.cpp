// SDL2 Hello, World!
// This should display a white screen for 2 seconds
// compile with: clang++ main.cpp -o hello_sdl2 -lSDL2
// run with: ./hello_sdl2

#include "Game.h"

int main(int argc, char* args[]) 
{
	Game* game = new Game();
    game->Init();
	// main game setup
    const int FPS = 60;
    const int frameSync = 1000;
    const int frameDelay = frameSync / FPS;
    // delta time setup
    float deltaTime = 0.0f;
    int thisTime = 0;
    int lastTime = 0;
    int frameTime = 0;

    // main game loop start
	while (game->IsRunning())
	{
        thisTime = SDL_GetTicks();
        deltaTime = ((float)thisTime - lastTime) / frameSync;
        lastTime = thisTime;

		game->Update(deltaTime);

        frameTime = SDL_GetTicks() - thisTime;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
	}

    // end game and free space
    delete game;
	return 0;
}