#include "Tile.hpp"
#include <queue>

using namespace std;

Tile::Tile() {
	this->value = 0;
	this->innerValue = 0;
}

Tile Tile::generateTile(int value, int innerValue) {
	Tile tempTile = Tile();
	tempTile.value = value;
	tempTile.innerValue = innerValue;
	return tempTile;
}

bool Tile::equalTiles(Tile tile1, Tile tile2) {
	bool equals = false;
	if (tile1.value == tile2.value && tile1.innerValue == tile2.innerValue) {
		equals = true;
	}
	return equals;
}

Tile::~Tile() {

}

