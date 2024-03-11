#include "Draw.hpp"
#include <SDL2/SDL.h>
#define C_X 400
#define C_Y 150

Draw::Draw() {

}

void Draw::drawCube(SDL_Renderer* renderer, int *attributes, int *pos, bool *adjacent) {
	int slope = *attributes;
	int length = *(attributes + 1);
	int xPos = *pos;
	int yPos = *(pos + 1);
	int zPos = *(pos + 2);
	int x = C_X + (xPos * length) - (zPos * length);
	int y = C_Y - (yPos * length) + (xPos * slope) + (zPos * slope);
	SDL_RenderDrawLine(renderer, x, y + slope, x, y + length + slope);
	SDL_RenderDrawLine(renderer, x, y + slope, x + length, y);
	SDL_RenderDrawLine(renderer, x, y + slope, x - length, y);
	if (!(*adjacent)) {
		SDL_RenderDrawLine(renderer, x, y + length + slope, x + length, y + length);
		SDL_RenderDrawLine(renderer, x + length, y, x + length, y + length);
	}
	if (!(*(adjacent + 2))) {
		SDL_RenderDrawLine(renderer, x, y + length + slope, x - length, y + length);
		SDL_RenderDrawLine(renderer, x - length, y, x - length, y + length);
	}
	if (!(*(adjacent + 1))) {
		SDL_RenderDrawLine(renderer, x - length, y, x, y - slope);
		SDL_RenderDrawLine(renderer, x + length, y, x, y - slope);
	}
}

Draw::~Draw() {

}