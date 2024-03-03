#include "MapTile2.hpp"
#include "Tile.hpp"
#include "MapTilePair.hpp"

MapTile2::MapTile2(){
	this->numTiles = 0;
}

void MapTile2::addTile(int coords[2], Tile tile1) {
	MapTilePair temp = MapTilePair();
	temp.newPair(coords, tile1);
	this->tilePairs.push(temp);
	this->numTiles++;
}

Tile MapTile2::removeTile(int coords[2]) {
	Tile removedTile = Tile();
	bool found = false;
	for (int i = 0; !found && i < this->numTiles; i++) {
		MapTilePair temp = this->tilePairs.front();
		this->tilePairs.pop();
		if (temp.getCoords() == coords) {
			removedTile = temp.getTile();
			found = true;
		} else {
			this->tilePairs.push(temp);
		}
	}
	this->numTiles--;
	return removedTile;
}

bool MapTile2::hasTile(int coords[2]) {
	bool hasTile = false;
	for (int i = 0; !hasTile && i < this->numTiles; i++) {
		MapTilePair temp = this->tilePairs.front();
		if (temp.getCoords() == coords) {
			hasTile = true;
		}
		this->tilePairs.pop();
		this->tilePairs.push(temp);
	}
	return hasTile;
}

void MapTile2::replaceTile(int coords[2], Tile tile1) {
	bool hasTile = false;
	for (int i = 0; !hasTile && i < this->numTiles; i++) {
		MapTilePair temp = this->tilePairs.front();
		if (temp.getCoords() == coords) {
			temp.changeTile(tile1);
		}
		this->tilePairs.pop();
		this->tilePairs.push(temp);
	}
}

MapTile2::~MapTile2() {

}