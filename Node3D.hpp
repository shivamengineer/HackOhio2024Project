#ifndef NODE3D_H
#define NODE3D_H
#include "MapTilePair.hpp"

class Node3D {
	private:
		MapTilePair pair;
		Node3D* xyz;
		Node3D* yxz;
		Node3D* zyx;
	public:
		Node3D();
		void insertNode(MapTilePair pair);
		MapTilePair removeNode(int coords[2]);
		MapTilePair getNode(int coords[2]);
		~Node3D();
};

#endif