#include "MapTilePair.hpp"
#include "Tile.hpp"
#include <stdlib.h>

MapTilePair::MapTilePair() {
	this->coords[0] = 0;
	this->coords[1] = 0;
	this->coords[2] = 0;
	this->tile = Tile();
	this->adjacent = (bool*)calloc(3, sizeof(bool));
}

MapTilePair::MapTilePair(int coords[3], Tile tile) {
	this->coords[0] = coords[0];
	this->coords[1] = coords[1];
	this->coords[2] = coords[2];
	this->tile = tile;
	this->adjacent = (bool*)calloc(3, sizeof(bool));
}

MapTilePair::MapTilePair(int coords[3], Tile tile, bool* adjacent1) {
	this->coords[0] = coords[0];
	this->coords[1] = coords[1];
	this->coords[2] = coords[2];
	this->tile = tile;
	this->adjacent = (bool*)calloc(3, sizeof(bool));
	if (this->adjacent != NULL) {
		*(this->adjacent) = adjacent1[0];
		*(this->adjacent + 1) = adjacent1[1];
		*(this->adjacent + 2) = adjacent1[2];
	}
}

int* MapTilePair::getCoords() {
	return this->coords;
}

Tile MapTilePair::getTile() {
	return this->tile;
}

void MapTilePair::changeTile(Tile tile) {
	this->tile = tile;
}

bool* MapTilePair::getAdjacent() {
	return this->adjacent;
}

void MapTilePair::changeAdjacent(bool newAdjacent[3]) {
	*(adjacent) = newAdjacent[0];
	*(adjacent + 1) = newAdjacent[1];
	*(adjacent + 1) = newAdjacent[2];
}

MapTilePair::~MapTilePair() {
	free(this->adjacent);
}