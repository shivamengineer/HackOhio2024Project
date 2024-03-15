#ifndef DRAW_H
#define DRAW_H
#include <SDL2/SDL.h>
#include <vector>

class Draw {
	private:

	public:
		Draw();
		//renderer, slope, length, x, y, z
		void drawCube(SDL_Renderer* renderer, int *attributes, int *pos, bool *adjacent);
		~Draw();
};

#endif