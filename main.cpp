#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "MapTile.hpp"
#include "Draw.hpp"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	int WIDTH = 1000, HEIGHT = 480;

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

	SDL_Rect background{0, 0, WIDTH, HEIGHT};

	Draw temp = Draw();

	int slope, lengthCube, posX, posY;
	slope = 23;
	lengthCube = 50;
	posX = 2;
	posY = 0;

	int posX2, posY2;

	SDL_Rect rect1 = {100, 100, 50, 50};

	bool running = true;
	SDL_Event e;

	while (running) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			running = false;
		}

		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &background);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		temp.drawCube(renderer, slope, lengthCube, 2, 0);
		temp.drawCube(renderer, slope, lengthCube, 0, 0);
		temp.drawCube(renderer, slope, lengthCube, 1, 1);
		temp.drawCube(renderer, slope, lengthCube, 1, -1);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}