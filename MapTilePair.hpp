#ifndef MAPTILEPAIR_H
#define MAPTILEPAIR_H
#include "Tile.hpp"

class MapTilePair {
	private:
		int coords[2];
		Tile tile;
		bool* adjacent;
	public:
		MapTilePair();
		MapTilePair(int coords[2], Tile tile);
		MapTilePair(int coords[2], Tile tile, bool* adjacent1);
		int* getCoords();
		Tile getTile();
		void changeTile(Tile tile);
		bool* getAdjacent();
		void changeAdjacent(bool newAdjacent[3]);
		~MapTilePair();
};

#endif