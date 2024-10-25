#include "HexagonMap.hpp"
#include "Hexagon.hpp"
#include <queue>

HexagonMap::HexagonMap() {
	
}

void HexagonMap::adjustHashTableSize() {
	
}

void HexagonMap::insertHexagon(Hexagon hex) {
	/*for(int i = 0; i < 20; i++){
		hexBuckets[i].push(...);
	}*/
	hexBuckets.push(hex);
}

Hexagon HexagonMap::removeHexagon(int pos[2]) {
	bool found = false;
	for (int i = 0; !found && i < hexBuckets.size(); i++) {
		int* hexPos = hexBuckets.front().getPos();
		if (pos[0] == *hexPos && pos[1] == *(hexPos + 1)) {
			found = true;
			Hexagon temp = hexBuckets.front();
			hexBuckets.pop();
			return temp;
		}
	}
	return Hexagon(0, 0, 0, SDL_Color{0, 0, 0, 0}, SDL_Color{0, 0, 0, 0});
}

bool HexagonMap::hasKey(int pos[2]) {
	for (int i = 0; i < hexBuckets.size(); i++) {
		int* hexPos = hexBuckets.front().getPos();
		if (pos[0] == *hexPos && pos[1] == *(hexPos + 1)) {
			return true;
		}
	}
	return false;
}

HexagonMap::~HexagonMap() {

}