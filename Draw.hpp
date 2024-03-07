#ifndef DRAW_H
#define DRAW_H
#include <SDL2/SDL.h>

class Draw {
	private:

	public:
		Draw();
		void drawCube(SDL_Renderer* renderer, int slope, int length, int xPos, int yPos, int zPos);
		~Draw();
};

#endif