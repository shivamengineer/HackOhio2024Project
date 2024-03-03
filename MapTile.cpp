#include "MapTile.hpp"
#include "MapTile2.hpp"
#include "Tile.hpp"
#include "Math.hpp"

MapTile::MapTile(){
	this->numTiles = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->mapInit[i][j] = false;
		}
	}
	this->maps = (MapTile2*)malloc(100*sizeof(MapTile2));
}

void MapTile::addTile(int coords[2], Tile tile1) {
	Math math = Math();
	int* bucket = (int*)malloc(2 * sizeof(int));
	bucket = math.bucket(coords);
	if (mapInit[*bucket][*(bucket + 1)] == false) {
		mapInit[*bucket][*(bucket + 1)] = true;
		*(this->maps + *bucket + (*(bucket + 1) * 10)) = MapTile2();
	}
	(this->maps + *bucket + (*(bucket + 1) * 10))->addTile(coords, tile1);
	this->numTiles++;
}

Tile MapTile::removeTile(int coords[2]) {
	Math math = Math();
	int* bucket = (int*)malloc(2 * sizeof(int));
	bucket = math.bucket(coords);
	(this->maps + *bucket + (*(bucket + 1) * 100))->removeTile(coords);
	return Tile();
}

bool MapTile::hasTile(int coords[2]) {
	bool hasTile = false;
	Math math = Math();
	int* bucket = (int*)malloc(2 * sizeof(int));
	bucket = math.bucket(coords);
	if ((this->maps + *bucket + (*(bucket + 1) * 10))->hasTile(coords)) {
		hasTile = true;
	}
	return hasTile;
}

void MapTile::replaceTile(int coords[2], Tile tile1) {
	Math math = Math();
	int* bucket = (int*)malloc(2 * sizeof(int));
	bucket = math.bucket(coords);
	(this->maps + *bucket + (*(bucket + 1) * 100))->replaceTile(coords, tile1);
}

MapTile::~MapTile() {
	free(this->maps);
}