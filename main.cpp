#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "MapTile.hpp"
#include "Draw.hpp"
#include "Collide.hpp"

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	int WIDTH = 1000, HEIGHT = 480;

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_DisplayMode dm;

	bool fullscreen = false;

	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

	TTF_Font* roboto = TTF_OpenFont("include/roboto/Roboto-Medium.ttf", 30);
	if (roboto == NULL) {
		printf("NULL error");
	}

	SDL_Surface* surface = TTF_RenderText_Solid(roboto, "Hello World!", {255, 255, 255});
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	Draw temp = Draw();
	Collide collider = Collide();

	int slope, lengthCube, posX, posY;
	slope = 23;
	lengthCube = 50;
	posX = 2;
	posY = 0;

	int posX2, posY2;

	SDL_Rect rect1 = { 20, 20, 200, 30 };

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
	int* mouseX = (int*)calloc(1, sizeof(int));
	int* mouseY = (int*)calloc(1, sizeof(int));

	/*int pos1[3] = {0, 0, 0};
	int pos2[3] = { 0, 0, 1 };
	int pos3[3] = { 1, 0, 0 };
	int pos4[3] = { 0, 1, 0 };
	int pos5[3] = { -1, 1, 0 };*/

	if (SDL_GetDesktopDisplayMode(0, &dm)) {
		printf("Error getting display mode\n");
		return -1;
	}

	bool running = true;
	SDL_Event event;

	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	while (running) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			if (event.type = SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_f:
					if (!fullscreen) {
						SDL_RestoreWindow(window);
						SDL_SetWindowSize(window, dm.w, dm.h + 10);
						SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
						fullscreen = true;
					} else {
						SDL_RestoreWindow(window);
						SDL_SetWindowSize(window, WIDTH, HEIGHT);
						SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
						fullscreen = false;
					}
					break;
				}
			}
			if (event.type = SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(mouseX, mouseY);
				int* mouseCoords = (int*)calloc(2, sizeof(int));
				if (mouseX != NULL && mouseCoords != NULL) {
					*mouseCoords = *mouseX;
				}
				if (mouseY != NULL && mouseCoords != NULL) {
					*(mouseCoords + 1) = *mouseY;
				}
				bool collides = collider.mouseObjectCollide(attribs, pos, mouseCoords, adjacent);
				if (collides) {
					printf("Collides\n");
				} else {
					printf("Does not collide\n");
				}
				free(mouseCoords);
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		SDL_RenderCopy(renderer, texture, NULL, &rect1);

		temp.drawCube(renderer, attribs, pos, adjacent);
		/*temp.drawCube(renderer, attribs, pos2);
		temp.drawCube(renderer, attribs, pos3);
		temp.drawCube(renderer, attribs, pos4);
		temp.drawCube(renderer, attribs, pos5);*/

		SDL_RenderPresent(renderer);
	}

	free(mouseX);
	free(mouseY);
	free(attribs);
	free(pos);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);

	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}