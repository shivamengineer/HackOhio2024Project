#ifndef MAPTILE_H
#define MAPTILE_H
#include "Tile.hpp"
#include "MapTile1.hpp"

class MapTile {
	private:
		int numTiles;
		MapTile1* maps;
		bool mapInit[10][10];
	public:
		MapTile();
		void addPair(MapTilePair pair);
		MapTilePair getPair(int coords[3]);
		MapTilePair removeTile(int coords[3]);
		bool hasTile(int coords[3]);
		void replaceTile(MapTilePair newPair);
		~MapTile();
};

#endif