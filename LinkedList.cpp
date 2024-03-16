#include "LinkedList.hpp"
#include "Tile.hpp"

LinkedList::LinkedList(){
	this->leftLength = 0;
	this->rightLength = 0;
	this->preStart = new Node();
	this->postFinish = new Node();
	this->preStart->next = this->postFinish;
	this->postFinish->previous = this->preStart;
	this->current = this->preStart;
}

void LinkedList::insert(MapTilePair pair){
	Node* temp = new Node();
	temp->pair = pair;
	int* coords = (int*)calloc(2, sizeof(int));
	coords = pair.getCoords();
	bool inserted = false;
	while (!inserted) {
		int* currentCoords = (int*)calloc(3, sizeof(int));
		currentCoords = this->current->pair.getCoords();

		int* nextCoords = (int*)calloc(3, sizeof(int));
		nextCoords = this->current->next->pair.getCoords();
		
		int* previousCoords = (int*)calloc(3, sizeof(int));
		previousCoords = this->current->previous->pair.getCoords();

		if (((*coords > *currentCoords)||
			((*coords == *currentCoords)&&(*(coords + 1) > *(currentCoords + 1)))||
			((*coords == *currentCoords)&&(*(coords + 1) == *(currentCoords + 1)&&
			(*(coords + 2) > *(currentCoords + 2)))))&&
			((*coords > *currentCoords) ||
			((*coords == *nextCoords) && (*(coords + 1) > *(nextCoords + 1))) ||
			((*coords == *nextCoords) && (*(coords + 1) == *(nextCoords + 1) &&
			(*(coords + 2) > *(nextCoords + 2)))))){
			advance();
		} else if (((*coords > *currentCoords) ||
			((*coords == *currentCoords) && (*(coords + 1) > *(currentCoords + 1))) ||
			((*coords == *currentCoords) && (*(coords + 1) == *(currentCoords + 1) &&
			(*(coords + 2) > *(currentCoords + 2))))) &&
			((*coords < *currentCoords) ||
			((*coords == *nextCoords) && (*(coords + 1) < *(nextCoords + 1))) ||
			((*coords == *nextCoords) && (*(coords + 1) == *(nextCoords + 1) &&
			(*(coords + 2) < *(nextCoords + 2)))))) {
			//insert();
			temp->next = this->current->next;
			temp->previous = this->current->previous;
			temp->next->previous = temp;
			this->current->next = temp;
			this->rightLength++;
			inserted = true;
		} else if (((*coords > *currentCoords) ||
			((*coords == *currentCoords) && (*(coords + 1) < *(currentCoords + 1))) ||
			((*coords == *currentCoords) && (*(coords + 1) == *(currentCoords + 1) &&
			(*(coords + 2) < *(currentCoords + 2)))))){
			reverse();
			if (((*coords > *previousCoords) ||
				((*coords == *previousCoords) && (*(coords + 1) > *(previousCoords + 1))) ||
				((*coords == *previousCoords) && (*(coords + 1) == *(previousCoords + 1) &&
				(*(coords + 2) > *(previousCoords + 2)))))) {
				//insert();
				temp->next = this->current->next;
				temp->previous = this->current->previous;
				temp->next->previous = temp;
				this->current->next = temp;
				this->rightLength++;
				inserted = true;
			}
		}
		free(currentCoords);
		free(nextCoords);
		free(previousCoords);
	}

	free(coords);
}

MapTilePair LinkedList::remove(int coords[2]) {
	bool removed = false;
	this->current = this->preStart;
	this->rightLength += this->leftLength;
	this->leftLength = 0;
	MapTilePair temp = MapTilePair();
	while (!removed && this->rightLength > 0) {
		int* coords = this->current->next->pair.getCoords();
		if (*coords == coords[0] && *(coords + 1) == coords[1]) {
			temp = this->current->next->pair;
			this->current->next->next->previous = this->current;
			this->current->next = this->current->next->next;
			this->rightLength;
			removed = true;
		} else {
			advance();
		}
	}
	return temp;
}

MapTilePair LinkedList::getPair(int coords[2]) {
	bool found = false;
	this->current = this->preStart;
	this->rightLength += this->leftLength;
	this->leftLength = 0;
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
	this->rightLength += this->leftLength;
	this->leftLength = 0;
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
	this->leftLength++;
	this->rightLength--;
}

void LinkedList::reverse() {
	this->current = this->current->previous;
	this->leftLength--;
	this->rightLength++;
}

LinkedList::~LinkedList() {

}