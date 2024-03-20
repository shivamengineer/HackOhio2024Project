#include "Draw.hpp"
#include <SDL2/SDL.h>
#define C_X 400
#define C_Y 150
#include <vector>
#include <queue>

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
	unsigned char opacity = (unsigned char)*(attributes + 2);
	float fx = (float)x;
	float fy = (float)y;
	float fslope = (float)slope;
	float flength = (float)length;
	if (!(*adjacent)) {
		//draw face
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, opacity);
		std::vector<SDL_Vertex> vertex1 = {
			{ SDL_FPoint{fx, fy + fslope}, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx, fy + fslope + flength }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx + flength, fy }, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
		};
		std::vector<SDL_Vertex> vertex2 = {
			{ SDL_FPoint{fx + flength, fy}, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{ fx, fy + fslope + flength}, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{ fx + flength, fy + flength }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
		};
		SDL_RenderGeometry(renderer, nullptr, vertex1.data(), vertex1.size(), nullptr, 0);
		SDL_RenderGeometry(renderer, nullptr, vertex2.data(), vertex2.size(), nullptr, 0);
		//draw edges
		SDL_RenderDrawLine(renderer, x, y + length + slope, x + length, y + length);
		SDL_RenderDrawLine(renderer, x + length, y, x + length, y + length);
	}
	if (!(*(adjacent + 1))) {
		//draw face
		std::vector<SDL_Vertex> vertex1 = {
			{ SDL_FPoint{fx, fy + fslope}, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx, fy - fslope }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx - flength, fy }, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
		};
		std::vector<SDL_Vertex> vertex2 = {
			{ SDL_FPoint{fx, fy + fslope}, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx, fy - fslope }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx + flength, fy }, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
		};
		SDL_RenderGeometry(renderer, nullptr, vertex1.data(), vertex1.size(), nullptr, 0);
		SDL_RenderGeometry(renderer, nullptr, vertex2.data(), vertex2.size(), nullptr, 0);
		//draw edges
		SDL_RenderDrawLine(renderer, x - length, y, x, y - slope);
		SDL_RenderDrawLine(renderer, x + length, y, x, y - slope);
		
	}
	if (!(*(adjacent + 2))) {
		//draw face
		std::vector<SDL_Vertex> vertex1 = {
			{ SDL_FPoint{fx, fy + fslope}, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx, fy + flength + fslope }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{ fx - flength, fy }, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
		};
		std::vector<SDL_Vertex> vertex2 = {
			{ SDL_FPoint{fx, fy + flength + fslope}, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx - flength, fy }, SDL_Color{ 50, 50, 50, opacity }, SDL_FPoint{ 0 }, },
			{ SDL_FPoint{fx - flength, fy + flength }, SDL_Color{ 255, 255, 255, opacity }, SDL_FPoint{ 0 }, },
		};
		SDL_RenderGeometry(renderer, nullptr, vertex1.data(), vertex1.size(), nullptr, 0);
		SDL_RenderGeometry(renderer, nullptr, vertex2.data(), vertex1.size(), nullptr, 0);
		//draw edges
		SDL_RenderDrawLine(renderer, x, y + length + slope, x - length, y + length);
		SDL_RenderDrawLine(renderer, x - length, y, x - length, y + length);
	}
	//draw front edges
	SDL_RenderDrawLine(renderer, x, y + slope, x, y + length + slope);
	SDL_RenderDrawLine(renderer, x, y + slope, x + length, y);
	SDL_RenderDrawLine(renderer, x, y + slope, x - length, y);
}

Draw::~Draw() {

}