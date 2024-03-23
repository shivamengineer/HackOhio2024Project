#include "MapTile1.hpp"
#include "LinkedList.hpp"
#include "Math.hpp"

MapTile1::MapTile1(){
	this->maps = (LinkedList*)calloc(25, sizeof(LinkedList));
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++){
			this->mapInit[i][j] = false;
		}
	}
	this->numTiles = 0;
}

void MapTile1::addTile(int coords[2], Tile tile1) {
	Math math = Math();
	MapTilePair pair = MapTilePair(coords, tile1);
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	if (mapInit[*bucket][*(bucket + 1)] == false) {
		mapInit[*bucket][*(bucket + 1)] = true;
		*(this->maps + *bucket + (*(bucket + 1) * 2)) = LinkedList();
	}
	(this->maps + *bucket + (*(bucket + 1) * 2))->insert(pair);
	this->numTiles++;
	free(bucket);
}

Tile MapTile1::removeTile(int coords[2]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	(this->maps + *bucket + (*(bucket + 1) * 2))->remove(coords);
	free(bucket);
	return Tile();
}

bool MapTile1::hasTile(int coords[2]) {
	Math math = Math();
	int* bucket = (int*)calloc(2, sizeof(int));
	bucket = math.miniBucket(coords);
	//(this->maps + *bucket + (*(bucket + 1) * 2))
}

void MapTile1::replaceTile(int coords[2], Tile tile1) {

}

MapTile1::~MapTile1() {

}