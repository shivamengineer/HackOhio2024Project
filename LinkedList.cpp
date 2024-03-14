#include "LinkedList.hpp"
#include "Tile.hpp"

LinkedList::LinkedList(){
	this->leftLength = 0;
	this->rightLength = 0;
	this->preStart = new Node();
	this->postFinish = new Node();
	this->preStart->nXZY = this->postFinish;
	this->preStart->nZXY = this->postFinish;
	this->postFinish->pXZY = this->preStart;
	this->postFinish->pZXY = this->preStart;
	this->current = this->preStart;
}

void LinkedList::insert(MapTilePair pair){
	Node* temp = new Node();
	temp->pair = pair;
	int* coords = (int*)calloc(2, sizeof(int));
	coords = pair.getCoords();
	bool xz[2] = { false, false };
	while (!(xz[0])) {
		int* tempCoords = (int*)calloc(3, sizeof(int));
		tempCoords = this->current->pair.getCoords();

		int* nextCoords = (int*)calloc(3, sizeof(int));
		nextCoords = this->current->nXZY->pair.getCoords();
		
		//0 advance, 1 insert, 2 check z/y, 3 check next z/y
		int action;
		if (*coords > *tempCoords && *coords > *nextCoords) {
			action = 0;
		} else if ((*coords < *tempCoords)||(*coords > *tempCoords && *coords < *nextCoords)){
			action = 1;
		} else if(*coords == *tempCoords){
			action = 2;
		} else if(*coords > *tempCoords && *tempCoords == *nextCoords){
			action = 3;
			if (*(coords + 1) > *(nextCoords + 1)) {
				action = 0;
			} else if(*(coords + 1) < *(nextCoords + 1)){
				action = 1;
			} else {
				if (*(coords + 2) > *(nextCoords + 2)) {
					action = 0;
				} else if(*(coords + 2) < *(nextCoords + 2)){
					action = 1;
				}
			}
		}
	}
	while (!(xz[0])) {

	}

	free(coords);
}

MapTilePair LinkedList::remove(int coords[2]) {
	return MapTilePair();
}

MapTilePair LinkedList::getPair(int coords[2]) {
	return MapTilePair();
}

void LinkedList::replace(int coords[2], Tile tile){

}

void LinkedList::advance() {

}

LinkedList::~LinkedList() {

}