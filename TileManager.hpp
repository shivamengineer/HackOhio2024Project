#ifndef TILEMANAGER_H
#define TILEMANAGER_H
#include <queue>
#include "Hexagon.hpp"
#include "HexagonMap.hpp"

class TileManager {
	private:
		std::queue<Hexagon> hexagons;
		HexagonMap hexMap = HexagonMap();
		int topCorner[2];
		void setTopCorner(int camPos[2]);
	public:
		TileManager();
		void UpdateCurrentTiles(int cameraPos[2]);
		~TileManager();
};

#endif