#include "stdafx.h"

Tile::Tile(int x, int y, string texID) {
	xPos = x;
	yPos = y;
	textureID = texID;
}

Tile::~Tile() {
}

void Tile::addtoVAO(VAO vao) {

}
