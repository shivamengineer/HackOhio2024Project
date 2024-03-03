#ifndef TILE_H
#define TILE_H
#include <queue>

class Tile {
	private:
		int value;
		int innerValue;
	public:
		Tile();
		bool equalTiles(Tile tile1, Tile tile2);
		Tile generateTile(int value, int innerValue);
		~Tile();
};
#endif