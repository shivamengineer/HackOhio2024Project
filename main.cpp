#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "Collide.hpp"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	int WIDTH = 1000, HEIGHT = 480;
	int opacityMain = 255;
	int opacityMenu = 0;
	bool blur = false;
	int keyCount = 0;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_DisplayMode dm;

	bool fullscreen = false, resume = false, exit = false;

	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

	TTF_Font* roboto = TTF_OpenFont("include/roboto/Roboto-Medium.ttf", 30);

	SDL_Surface* escSurface = TTF_RenderText_Solid(roboto, "ESC", { 255, 255, 255 });
	SDL_Texture* escTexture = SDL_CreateTextureFromSurface(renderer, escSurface);
	SDL_Rect esc = { 50, 50, 100, 30 };

	if (SDL_GetDesktopDisplayMode(0, &dm)) {
		printf("Error getting display mode\n");
		return -1;
	}

	bool running = true;
	SDL_Event event;

	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	while (running) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type = SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_q:
					running = false;
					break;
				case SDLK_f:
					if (!fullscreen) {
						SDL_RestoreWindow(window);
						SDL_SetWindowSize(window, dm.w, dm.h + 10);
						SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
						fullscreen = true;
					}
					else {
						SDL_RestoreWindow(window);
						SDL_SetWindowSize(window, WIDTH, HEIGHT);
						SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
						fullscreen = false;
					}
					break;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderCopy(renderer, escTexture, NULL, &esc);

		SDL_RenderPresent(renderer);
	}

	SDL_FreeSurface(escSurface);
	SDL_DestroyTexture(escTexture);

	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}