#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(1000, 480, 0, &window, &renderer);

	TTF_Font *textFont = TTF_OpenFont("roboto/Roboto-Bold.ttf", 24);
	SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, "Hello World!", { 255, 255, 255 });
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_Rect background{0, 0, 1000, 480};
	SDL_Rect rect1 = SDL_Rect();
	rect1.x = 100; rect1.y = 100; rect1.w = 100; rect1.h = 100;

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

		SDL_RenderCopy(renderer, textTexture, NULL, &rect1);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}