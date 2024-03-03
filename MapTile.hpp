#ifndef MAPTILE_H
#define MAPTILE_H
#include "Tile.hpp"
#include "MapTile2.hpp"

class MapTile {
	private:
		int numTiles;
		MapTile2* maps;
		bool mapInit[10][10];
	public:
		MapTile();
		void addTile(int coords[2], Tile tile1);
		Tile removeTile(int coords[2]);
		bool hasTile(int coords[2]);
		void replaceTile(int coords[2], Tile tile1);
		~MapTile();
};

#endif