#include "UpdateWorld.hpp"
#include "SDL2/SDL.h"

UpdateWorld::UpdateWorld(SDL_Renderer* renderer, int* attribs) {
	this->renderer = renderer;
	this->attribs = attribs;
	this->map = MapTile2();
}

UpdateWorld::~UpdateWorld() {

}