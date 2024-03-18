#include "Collide.hpp"
#include "SDL2/SDL.h"


Collide::Collide(){
	this->C_X = 400;
	this->C_Y = 150;
}

bool Collide::mouseRectCollide(SDL_Rect rect1, int* mousePos) {
	return (*mousePos > rect1.x && *mousePos < rect1.x + rect1.w &&
		*(mousePos + 1) > rect1.y && *(mousePos + 1) < rect1.y + rect1.h);
}

bool Collide::mouseObjectCollide(int* attributes, int* pos, int* mousePos, bool* adjacent) {
	int slope = *attributes;
	int length = *(attributes + 1);
	int x = this->C_X + (*pos * length) - (*(pos + 2) * length);
	int y = this->C_Y + (*(pos+1) * length) + (*pos * slope) + (*(pos + 2) * slope);
	bool collides = false;
	if (!(*adjacent)) {
		if (*mousePos >= x && *mousePos <= x + length &&
			*(mousePos + 1) >= ((-length / slope) * (*mousePos - x)) + y + slope &&
			*(mousePos + 1) <= ((-length / slope) * (*mousePos - x - length) + y + length)) {
			collides = true;
		}
	}
	if (!collides && !(*(adjacent + 1))) {
		if (*(mousePos + 1) <= ((length/slope)*(*mousePos - x)) + y + slope &&
			*(mousePos + 1) <= ((-length/slope)*(*mousePos - x)) + y + slope &&
			*(mousePos + 1) >= ((-length/slope)*(*mousePos - x + length)) + y &&
			*(mousePos + 1) >= ((length/slope)*(*mousePos - x - length)) + y) {
			collides = true;
		}
	}
	if (!collides && !(*(adjacent + 2))) {
		if (*mousePos >= x - length && *mousePos <= x &&
			*(mousePos + 1) <= ((length/slope)*(*mousePos - x + length) + y + length) &&
			*(mousePos + 1) >= ((length/slope)*(*mousePos - x)) + y + slope) {
			collides = true;
		}
	}
	return collides;
}

Collide::~Collide() {

}