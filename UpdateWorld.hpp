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
	MapTile renderedMap;
public:
	UpdateWorld(SDL_Renderer* renderer, int* attribs);
	void setRenderedMap(int* center);
	void updateRenderedMap(int* center);
	void renderMap();
	~UpdateWorld();
};

#endif