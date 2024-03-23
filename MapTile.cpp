#include "MapTile.hpp"
#include "MapTile1.hpp"
#include "Tile.hpp"
#include "Math.hpp"

MapTile::MapTile(){
	this->numTiles = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->mapInit[i][j] = false;
		}
	}
	this->maps = (MapTile1*)calloc(100, sizeof(MapTile1));
}

void MapTile::addTile(int coords[2], Tile tile1) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	if (mapInit[*bucket][*(bucket + 1)] == false) {
		mapInit[*bucket][*(bucket + 1)] = true;
		*(this->maps + *bucket + (*(bucket + 1) * 10)) = MapTile1();
	}
	(this->maps + *bucket + (*(bucket + 1) * 10))->addTile(coords, tile1);
	this->numTiles++;
	free(bucket);
}

Tile MapTile::getTile(int coords[2]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	return Tile();
}

Tile MapTile::removeTile(int coords[2]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	(this->maps + *bucket + (*(bucket + 1) * 10))->removeTile(coords);
	free(bucket);
	return Tile();
}

bool MapTile::hasTile(int coords[2]) {
	bool hasTile = false;
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	if ((this->maps + *bucket + (*(bucket + 1) * 10))->hasTile(coords)) {
		hasTile = true;
	}
	free(bucket);
	return hasTile;
}

void MapTile::replaceTile(int coords[2], Tile tile1) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	(this->maps + *bucket + (*(bucket + 1) * 100))->replaceTile(coords, tile1);
	free(bucket);
}

MapTile::~MapTile() {
	free(this->maps);
}