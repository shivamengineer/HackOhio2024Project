#include "Draw.hpp"
#include <SDL2/SDL.h>
#define C_X 400
#define C_Y 150

Draw::Draw() {

}

void Draw::drawCube(SDL_Renderer* renderer, int slope, int length, int x, int y) {
	x = C_X + (x * length);
	y = C_Y + (y * length) + (y * slope);
	SDL_RenderDrawLine(renderer, x, y + slope, x, y + length + slope);
	SDL_RenderDrawLine(renderer, x, y + slope, x + length, y);
	SDL_RenderDrawLine(renderer, x, y + slope, x - length, y);
	SDL_RenderDrawLine(renderer, x, y + length + slope, x + length, y + length);
	SDL_RenderDrawLine(renderer, x, y + length + slope, x - length , y + length);
	SDL_RenderDrawLine(renderer, x - length, y, x - length, y + length);
	SDL_RenderDrawLine(renderer, x + length, y, x + length, y + length);
	SDL_RenderDrawLine(renderer, x - length, y, x, y - slope);
	SDL_RenderDrawLine(renderer, x + length, y, x, y - slope);
}

Draw::~Draw() {

}