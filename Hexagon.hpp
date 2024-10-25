#ifndef HEXAGON_H
#define HEXAGON_H
#include "SDL2/SDL.h";
#include <vector>


class Hexagon {
	private:
		std::vector<SDL_Vertex> triangles[6];
		SDL_Vertex vertices[7];
		float centerPos[2];
		float size;
		void setVertices(int camX, int camY, SDL_Color innerColor, SDL_Color outerColor);
		void setTriangles();
	public:
		Hexagon(float x, float y, int hexagonSize, SDL_Color innerColor, SDL_Color outerColor);
		void Draw(SDL_Renderer* renderer);
		void Update(int camX, int camY, SDL_Color innerColor, SDL_Color outerColor);
		int* getPos();
		~Hexagon();
};

#endif