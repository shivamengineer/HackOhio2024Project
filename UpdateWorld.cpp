#include "UpdateWorld.hpp"
#include "SDL2/SDL.h"

UpdateWorld::UpdateWorld(SDL_Renderer* renderer, int* attribs) {
	this->renderer = renderer;
	this->attribs = attribs;
	this->map = MapTile();
	this->renderedMap = MapTile();
}

void UpdateWorld::setRenderedMap(int* center) {
	int slope = *(this->attribs);
	int length = *(this->attribs + 1);
}

void UpdateWorld::updateRenderedMap(int* center) {

}

void UpdateWorld::renderMap() {

}

UpdateWorld::~UpdateWorld() {

}