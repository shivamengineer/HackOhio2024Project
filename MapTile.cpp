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

void MapTile::addPair(MapTilePair pair) {
	Math math = Math();
	int* coords = pair.getCoords();

	int* bucketX = (int*)calloc(2, sizeof(int));
	int* coordsX = coords;
	*coordsX -= 1;

	int* bucketZ = (int*)calloc(2, sizeof(int));
	int* coordsZ = coords;

	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);

	int* coordsY = coords;
	
	if (mapInit[*bucket][*(bucket + 1)] == false) {
		mapInit[*bucket][*(bucket + 1)] = true;
		*(this->maps + *bucket + (*(bucket + 1) * 10)) = MapTile1();
	}
	(this->maps + *bucket + (*(bucket + 1) * 10))->addTile(pair);
	this->numTiles++;
	free(bucket);
}

MapTilePair MapTile::getPair(int coords[3]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	return (this->maps + *bucket + (*(bucket + 1) * 10))->getPair(coords);
}

MapTilePair MapTile::removeTile(int coords[3]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);
	MapTilePair pair = (this->maps + *bucket + (*(bucket + 1) * 10))->removeTile(coords);
	free(bucket);
	return pair;
}

bool MapTile::hasTile(int coords[3]) {
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

void MapTile::replaceTile(MapTilePair newPair) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(newPair.getCoords());
	(this->maps + *bucket + (*(bucket + 1) * 100))->replaceTile(newPair);
	free(bucket);
}

MapTile::~MapTile() {
	free(this->maps);
}