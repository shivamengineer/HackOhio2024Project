#include "Hexagon.hpp"

Hexagon::Hexagon(float x, float y, int hexagonSize, SDL_Color innerColor, SDL_Color outerColor) {
	this->centerPos[0] = x;
	this->centerPos[1] = y;
	this->size = hexagonSize;

	setVertices(0, 0, innerColor, outerColor);
	setTriangles();
}

void Hexagon::Draw(SDL_Renderer* renderer) {
	for (int i = 0; i < 6; i++) {
		SDL_RenderGeometry(renderer, nullptr, triangles[i].data(), triangles[i].size(), nullptr, 0);
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i = 1; i < 6; i++) {
		SDL_RenderDrawLine(renderer, vertices[i].position.x, vertices[i].position.y, vertices[i + 1].position.x,
			vertices[i + 1].position.y);
	}
	SDL_RenderDrawLine(renderer, vertices[1].position.x, vertices[1].position.y, vertices[6].position.x,
		vertices[6].position.y);
}

void Hexagon::Update(int camX, int camY, SDL_Color innerColor, SDL_Color outerColor) {
	setVertices(camX, camY, innerColor, outerColor);
	setTriangles();
}

void Hexagon::setVertices(int camX, int camY, SDL_Color innerColor, SDL_Color outerColor) {
	vertices[0] = { SDL_FPoint{centerPos[0] - camX, centerPos[1] - camY}, innerColor, SDL_FPoint{0} };
	vertices[1] = { SDL_FPoint{ centerPos[0] - camX - size, centerPos[1] - camY - size}, outerColor, SDL_FPoint{0} };
	vertices[2] = { SDL_FPoint{ centerPos[0] - camX + size, centerPos[1] - camY - size}, outerColor, SDL_FPoint{0} };
	vertices[3] = { SDL_FPoint{ centerPos[0] - camX + (2 * size), centerPos[1] - camY}, outerColor, SDL_FPoint{0} };
	vertices[4] = { SDL_FPoint{ centerPos[0] - camX + size, centerPos[1] - camY + size}, outerColor, SDL_FPoint{0} };
	vertices[5] = { SDL_FPoint{ centerPos[0] - camX - size, centerPos[1] - camY + size}, outerColor, SDL_FPoint{0} };
	vertices[6] = { SDL_FPoint{ centerPos[0] - camX - (2 * size), centerPos[1] - camY}, outerColor, SDL_FPoint{0} };
}

void Hexagon::setTriangles() {
	triangles[0] = { vertices[1], vertices[0], vertices[2] };
	triangles[1] = { vertices[2], vertices[0], vertices[3] };
	triangles[2] = { vertices[0], vertices[3], vertices[4] };
	triangles[3] = { vertices[0], vertices[5], vertices[4] };
	triangles[4] = { vertices[6], vertices[0], vertices[5] };
	triangles[5] = { vertices[1], vertices[6], vertices[0] };
}

int* Hexagon::getPos() {
	int* pos = (int*)malloc(2 * sizeof(int));
	*pos = centerPos[0];
	*(pos + 1) = centerPos[1];
	return pos;
}

Hexagon::~Hexagon() {

}