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
	void addTile(int coords[2], Tile tile1);
	Tile removeTile(int coords[2]);
	bool hasTile(int coords[2]);
	void replaceTile(int coords[2], Tile tile1);
	~MapTile1();
};

#endif