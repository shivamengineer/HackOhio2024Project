#include "LinkedList.hpp"
#include "Tile.hpp"
#include "MapTilePair.hpp"

typedef struct Node {
	MapTilePair pair;
	Node* next;
} Node;

LinkedList::LinkedList(){
	this->leftLength = 0;
	this->rightLength = 0;
	this->preStart.next = this->postFinish;
	this->current = &this->preStart;
}

void LinkedList::insert(MapTilePair pair){
	void gotoStart();
	this->rightLength += this->leftLength;
	this->leftLength = 0;
	Node* temp = this->current;
	temp->pair = pair;
	temp->next = this->current->next;
	this->current->next = temp;
	this->current->next = temp;
	this->rightLength++;
}

MapTilePair LinkedList::remove(int coords[2]) {
	bool removed = false;
	gotoStart();
	MapTilePair temp = MapTilePair(coords, Tile());
	while (!removed && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			temp = this->current->next->pair;
			this->current->next = this->current->next->next;
			this->rightLength--;
			removed = true;
		} else {
			advance();
		}
		free(coords);
	}
	return temp;
}

MapTilePair LinkedList::getPair(int coords[2]) {
	bool found = false;
	gotoStart();
	MapTilePair temp = MapTilePair(coords, Tile());
	while (!found && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			temp = this->current->next->pair;
			found = true;
		} else {
			advance();
		}
	}
	return temp;
}

bool LinkedList::hasPair(int coords[2]) {
	bool found = false;
	gotoStart();
	while (!found && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			found = true;
		} else {
			advance();
		}
	}

	return false;
}

void LinkedList::replace(int coords[2], Tile tile){
	bool replaced = false;
	gotoStart();
	MapTilePair temp = MapTilePair(coords, tile);
	while (!replaced && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			temp = this->current->next->pair;
			this->current->next->pair = temp;
			replaced = true;
		}
		else {
			advance();
		}
	}
}

void LinkedList::advance() {
	this->current = this->current->next;
	this->rightLength--;
}

void LinkedList::gotoStart() {
	this->current = &this->preStart;
	this->rightLength += this->leftLength;
	this->leftLength = 0;
}


LinkedList::~LinkedList() {

}