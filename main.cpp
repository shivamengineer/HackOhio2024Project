#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "MapTile.hpp"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(1000, 480, 0, &window, &renderer);

	SDL_Rect background{0, 0, 1000, 480};
	SDL_Rect rect1 = {100, 100, 100, 100};
	SDL_Rect rect2 = {100, 300, 100, 100};

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
		SDL_RenderDrawRect(renderer, &rect1);
		SDL_RenderDrawRect(renderer, &rect2);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}