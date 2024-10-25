#include "TileManager.hpp"
#include "Hexagon.hpp"
#define HEXAGON_SIZE 50
#define WIDTH 1000
#define HEIGHT 480

TileManager::TileManager() {
	hexagons = std::queue<Hexagon>();
	topCorner[0] = 0;
	topCorner[1] = 0;
}

void TileManager::setTopCorner(int camPos[2]) {

}

void TileManager::UpdateCurrentTiles(int cameraPos[2]) {

}

TileManager::~TileManager() {

}