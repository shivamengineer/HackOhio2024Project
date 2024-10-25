#ifndef HEXAGONMAP_H
#define HEXAGONMAP_H
#include "Hexagon.hpp"
#include <queue>

class HexagonMap {
	private:
		//std::queue<Hexagon> hexBuckets[20];
		std::queue<Hexagon> hexBuckets;
		void adjustHashTableSize();
	public:
		HexagonMap();
		void insertHexagon(Hexagon hex);
		Hexagon removeHexagon(int pos[2]);
		bool hasKey(int pos[2]);
		~HexagonMap();
};

#endif