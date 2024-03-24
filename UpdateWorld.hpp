#ifndef UPDATEWORLD_H
#define UPDATEWORLD_H
#include "MapTile.hpp"
#include "SDL2/SDL.h"
#include "Draw.hpp"

class UpdateWorld {
private:
	MapTile map;
	int* attribs;
	SDL_Renderer* renderer;
public:
	UpdateWorld(SDL_Renderer* renderer);
	void updateAdjacent();
	~UpdateWorld();
};

#endif