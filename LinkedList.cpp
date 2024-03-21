#include "LinkedList.hpp"
#include "Tile.hpp"

LinkedList::LinkedList(){
	this->leftLength = 0;
	this->rightLength = 0;
	this->preStart = new Node();
	this->postFinish = new Node();
	this->preStart->next = this->postFinish;
	this->current = this->preStart;
}

void LinkedList::insert(MapTilePair pair){
	this->current = this->preStart;
	this->rightLength += this->leftLength;
	this->leftLength = 0;
	Node* temp = new Node();
	temp->pair = pair;

	temp->next = this->current->next;
	this->current->next = temp;
	this->rightLength++;
}

MapTilePair LinkedList::remove(int coords[2]) {
	bool removed = false;
	this->current = this->preStart;
	MapTilePair temp = MapTilePair();
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
	this->current = this->preStart;
	MapTilePair temp = MapTilePair();
	while (!found && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			temp = this->current->next->pair;
			found = true;
		}
		else {
			advance();
		}
	}
	return temp;
}

void LinkedList::replace(int coords[2], Tile tile){
	bool replaced = false;
	this->current = this->preStart;
	MapTilePair temp = MapTilePair();
	temp.newPair(coords, tile);
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


LinkedList::~LinkedList() {

}