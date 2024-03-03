#ifndef MAPTILE2_H
#define MAPTILE2_H
#include "Tile.hpp"
#include "MapTilePair.hpp"

class MapTile2 {
private:
	int numTiles;
	std::queue<MapTilePair> tilePairs;
public:
	MapTile2();
	void addTile(int coords[2], Tile tile1);
	Tile removeTile(int coords[2]);
	bool hasTile(int coords[2]);
	void replaceTile(int coords[2], Tile tile1);
	~MapTile2();
};

#endif