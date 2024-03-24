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
		MapTilePair remove(int coords[3]);
		MapTilePair getPair(int coords[3]);
		bool hasPair(int coords[3]);
		void replace(MapTilePair newPair);
		~LinkedList();
};

#endif