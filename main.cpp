#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "MapTile.hpp"
#include "Draw.hpp"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	int WIDTH = 1000, HEIGHT = 480;

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

	SDL_Rect background{0, 0, WIDTH, HEIGHT};
	TTF_Font* roboto = TTF_OpenFont("roboto/Roboto-Bold.ttf", 24);

	SDL_Color white = { 225, 225, 225 };
	SDL_Surface* surface = TTF_RenderText_Solid(roboto, "Hello World!", white);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	Draw temp = Draw();

	int slope, lengthCube, posX, posY;
	slope = 23;
	lengthCube = 50;
	posX = 2;
	posY = 0;

	int posX2, posY2;

	SDL_Rect rect1 = {100, 100, 50, 50};
	int* attribs;
	attribs = (int*)calloc(2, sizeof(int));
	if (attribs != NULL) {
		*attribs = slope;
		*(attribs + 1) = lengthCube;
	}
	
	int* pos = (int*)calloc(3, sizeof(int));
	if (pos != NULL) {
		*pos = 0;
		*(pos + 1) = 0;
		*(pos + 2) = 0;
	}

	bool* adjacent = (bool*)calloc(3, sizeof(bool));
	if (adjacent != NULL) {
		*adjacent = false;
		*(adjacent + 1) = false;
		*(adjacent + 2) = false;
	}

	int pos1[3] = { 0, 0, 0 };
	int pos2[3] = { 0, 0, 1 };
	int pos3[3] = { 1, 0, 0 };
	int pos4[3] = { 0, 1, 0 };
	int pos5[3] = { -1, 1, 0 };

	bool running = true;
	SDL_Event e;

	while (running) {
		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT) {
			running = false;
		}

		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &background);

		SDL_RenderCopy(renderer, texture, NULL, &rect1);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		temp.drawCube(renderer, attribs, pos, adjacent);
		/*temp.drawCube(renderer, attribs, pos2);
		temp.drawCube(renderer, attribs, pos3);
		temp.drawCube(renderer, attribs, pos4);
		temp.drawCube(renderer, attribs, pos5);*/

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderPresent(renderer);
	}

	free(attribs);
	free(pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}