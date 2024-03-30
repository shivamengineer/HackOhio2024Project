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

	bool pairAdjacent[3] = { false, false, false };

	int* bucketX = (int*)calloc(2, sizeof(int));
	int* bucketX2 = (int*)calloc(2, sizeof(int));
	int* tempCoords = coords;
	*tempCoords -= 1;
	*coords += 1;
	bucketX = math.bucket(tempCoords);
	if ((this->maps + *bucketX + (*(bucketX + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucketX + (*(bucketX + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentX(true);
	}
	if ((this->maps + *bucketX2 + (*(bucketX2 + 1) * 10))->hasTile(coords)) {
		pair.changeAdjacentX(true);
	}
	*tempCoords += 1;
	*coords -= 1;
	bucketX2 = math.bucket(coords);
	free(bucketX);
	free(bucketX2);

	int* bucketZ = (int*)calloc(2, sizeof(int));
	int* bucketZ2 = (int*)calloc(2, sizeof(int));
	*(tempCoords + 2) -= 1;
	*(coords + 2) += 1;
	bucketZ = math.bucket(tempCoords);
	if ((this->maps + *bucketZ + (*(bucketZ + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucketZ + (*(bucketZ + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentZ(true);
	}
	*(tempCoords + 2) += 1;
	*(coords + 2) -= 1;
	free(bucketZ);
	free(bucketZ2);

	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);

	*(tempCoords + 1) -= 1;
	*(coords + 1) += 1;
	if ((this->maps + *bucket + (*(bucket + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucket + (*(bucket + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentY(true);
	}
	if ((this->maps + *bucket + (*(bucket + 1) * 10))->hasTile(coords)) {
		pair.changeAdjacentY(true);
	}
	*(tempCoords + 1) += 1;
	*(coords + 1) -= 1;
	
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
	int* bucketX = (int*)calloc(2, sizeof(int));
	int* tempCoords = coords;
	*tempCoords -= 1;
	bucketX = math.bucket(tempCoords);
	if ((this->maps + *bucketX + (*(bucketX + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucketX + (*(bucketX + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentX(false);
	}
	*tempCoords += 1;

	int* bucketZ = (int*)calloc(2, sizeof(int));
	*(tempCoords + 2) -= 1;
	bucketZ = math.bucket(tempCoords);
	if ((this->maps + *bucketZ + (*(bucketZ + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucketZ + (*(bucketZ + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentZ(false);
	}
	*(tempCoords + 2) += 1;

	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.bucket(coords);

	*(tempCoords + 1) -= 1;
	if ((this->maps + *bucket + (*(bucket + 1) * 10))->hasTile(tempCoords)) {
		MapTilePair temp = (this->maps + *bucket + (*(bucket + 1) * 10))->getPair(tempCoords);
		temp.changeAdjacentY(false);
	}
	*(tempCoords + 1) += 1;
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