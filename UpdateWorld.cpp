#include "UpdateWorld.hpp"
#include "SDL2/SDL.h"

UpdateWorld::UpdateWorld(SDL_Renderer* renderer) {
	this->renderer = renderer;
	this->attribs = attribs;
	this->map = MapTile();
}

void UpdateWorld::updateAdjacent() {

}

UpdateWorld::~UpdateWorld() {

}