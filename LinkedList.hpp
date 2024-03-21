#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "MapTilePair.hpp"

typedef struct Node{
	MapTilePair pair;
	struct Node* next;
} Node;

class LinkedList {
	private:
		Node *preStart;
		Node *postFinish;
		Node* current;
		int rightLength;
		int leftLength;
	public:
		LinkedList();
		void insert(MapTilePair pair);
		MapTilePair remove(int coords[2]);
		MapTilePair getPair(int coords[2]);
		void replace(int coords[2], Tile tile);
		void advance();
		~LinkedList();
};

#endif