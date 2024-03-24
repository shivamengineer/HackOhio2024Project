#include "MapTile1.hpp"
#include "LinkedList.hpp"
#include "Math.hpp"

MapTile1::MapTile1(){
	this->maps = (LinkedList*)calloc(4, sizeof(LinkedList));
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++){
			this->mapInit[i][j] = false;
		}
	}
	this->numTiles = 0;
}

void MapTile1::addTile(MapTilePair pair) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(pair.getCoords());
	if (mapInit[*bucket][*(bucket + 1)] == false) {
		mapInit[*bucket][*(bucket + 1)] = true;
		*(this->maps + *bucket + (*(bucket + 1) * 2)) = LinkedList();
	}
	(this->maps + *bucket + ((*(bucket + 1) * 2)))->insert(pair);
	this->numTiles++;
	free(bucket);
}

MapTilePair MapTile1::removeTile(int coords[3]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	MapTilePair pair = (this->maps + *bucket + ((*(bucket + 1) * 2)))->remove(coords);
	free(bucket);
	return pair;
}

bool MapTile1::hasTile(int coords[3]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	bool hasTile = (this->maps + *bucket + ((*(bucket + 1)) * 2))->hasPair(coords);
	free(bucket);
	return hasTile;
}

MapTilePair MapTile1::getPair(int coords[3]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	MapTilePair pair = (this->maps + *bucket + ((*(bucket + 1)) * 2))->getPair(coords);
	free(bucket);
	return pair;
}

void MapTile1::replaceTile(MapTilePair newPair) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(newPair.getCoords());
	(this->maps + *bucket + ((*(bucket + 1)) * 2))->replace(newPair);
	free(bucket);
}

MapTile1::~MapTile1() {
	free(this->maps);
}