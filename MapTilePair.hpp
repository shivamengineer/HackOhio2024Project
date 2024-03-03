#ifndef MAPTILEPAIR_H
#define MAPTILEPAIR_H
#include "Tile.hpp"

class MapTilePair {
	private:
		int coords[2];
		Tile tile;
	public:
		MapTilePair();

		void newPair(int coords[2], Tile tile);
		int* getCoords();
		Tile getTile();
		void changeTile(Tile tile);

		~MapTilePair();
};

#endif