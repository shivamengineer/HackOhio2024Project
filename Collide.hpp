#ifndef COLLIDE_H
#define COLLIDE_H

#include "SDL2/SDL.h"

class Collide {
	private:
		int C_X;
		int C_Y;
	public:
		Collide();
		bool mouseRectCollide(SDL_Rect rect1, int* mousePos);
		bool mouseObjectCollide(int* attributes, int* pos, int* mousePos, bool* adjacent);
		~Collide();
};

#endif