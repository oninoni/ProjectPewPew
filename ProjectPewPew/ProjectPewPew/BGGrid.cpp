#include "stdafx.h"

void BGGrid::buildVAO() {
	vao->generate(tileMap.size() * 6, buStaticDraw);

	vao->map(baWriteOnly);

	for (size_t i = 0; i < tileMap.size(); i++) {
		tileMap.at(i).addToVAO(vao);
	}

	vao->unmap();
}

BGGrid::BGGrid() {

}

BGGrid::BGGrid(int sX, int sY, Game* g)
{
	size.x = sX;
	size.y = sY;

    string s;

	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
            switch (rand() % 5)
            {
            case 0:
                s = "grass";
                break;
            case 1:
                s = "stone";
                break;
            case 2:
                s = "stone_sexy";
                break;
            case 3:
                s = "stone_bricks";
                break;
            case 4:
                s = "wooden_planks";
                break;
            }
            tileMap.push_back(Tile(x, y, s, g));
		}
	}

	vao = new VAO(g->getTextureShader());

	vao->addAttribute(2, "vpos");
	vao->addAttribute(2, "vtexcoord");
	vao->genAttributes();

	uniformLocation = g->getTextureShader()->getUniformLocation("model");

	buildVAO();
}


BGGrid::~BGGrid()
{
    delete vao;
}

void BGGrid::update(double deltaT) {

}

void BGGrid::render() {
	Matrix3 matrix42;
	matrix42.loadIdentity();
	glUniformMatrix3fv(uniformLocation, 1, blFalse, matrix42.ptr());
	vao->render();
}

ivec2 BGGrid::getSize() {
	return size;
}
