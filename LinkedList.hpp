#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "MapTilePair.hpp"

class LinkedList {

	typedef struct Node {
		MapTilePair pair;
		Node* next;
	} Node;

	private:
		Node preStart;
		Node* postFinish;
		Node* current;
		int rightLength;
		int leftLength;
		void advance();
		void gotoStart();
	public:
		LinkedList();
		void insert(MapTilePair pair);
		MapTilePair remove(int coords[2]);
		MapTilePair getPair(int coords[2]);
		bool hasPair(int coords[2]);
		void replace(int coords[2], Tile tile);
		~LinkedList();
};

#endif