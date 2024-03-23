#include "MapTilePair.hpp"

MapTilePair::MapTilePair(int coords[2], Tile tile) {
	this->coords[0] = coords[0];
	this->coords[1] = coords[1];
	this->tile = tile;
}

int* MapTilePair::getCoords() {
	int coords[2];
	coords[0] = this->coords[0];
	coords[1] = this->coords[1];
	return coords;
}

Tile MapTilePair::getTile() {
	return this->tile;
}

void MapTilePair::changeTile(Tile tile) {
	this->tile = tile;
}

MapTilePair::~MapTilePair() {

}