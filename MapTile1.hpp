#ifndef MAPTILE1_H
#define MAPTILE1_H
#include "Tile.hpp"
#include "MapTilePair.hpp"
#include "LinkedList.hpp"

class MapTile1 {
private:
	int numTiles;
	LinkedList* maps;
	bool mapInit[5][5];
public:
	MapTile1();
	void addTile(MapTilePair pair);
	MapTilePair removeTile(int coords[3]);
	bool hasTile(int coords[3]);
	MapTilePair getPair(int coords[3]);
	void replaceTile(MapTilePair newPair);
	~MapTile1();
};

#endif