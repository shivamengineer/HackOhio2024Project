#ifndef UPDATEWORLD_H
#define UPDATEWORLD_H
#include "MapTile2.hpp"
#include "SDL2/SDL.h"

class UpdateWorld {
private:
	MapTile2 map;
	int* attribs;
	SDL_Renderer* renderer;
public:
	UpdateWorld(SDL_Renderer* renderer, int* attribs);
	
	~UpdateWorld();
};

#endif