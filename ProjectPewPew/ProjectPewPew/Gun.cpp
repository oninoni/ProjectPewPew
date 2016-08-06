#include "stdafx.h"

Gun::Gun(Game * g) {
	player = g->getPlayer();
	textureMap = g->getTextureMap();

	gunVAO = new VAO(g->getTextureShader());
	gunVAO->generate(6, buDynamicDraw);

	textureMap->setTexture("laserGun");

	struct {
		vec2 pos;
		texcoord tex;
		texcoord minborder;
		texcoord maxborder;
	} data;

	data.minborder = textureMap->getMinBorder();
	data.maxborder = textureMap->getMaxBorder();

	gunVAO->map(baWriteOnly);
	data.pos = vec2(0, 0);
	data.tex = textureMap->getTexCoord(vec2(0, 0));
	gunVAO->addVertex(&data);
	data.pos = vec2(1, 0);
	data.tex = textureMap->getTexCoord(vec2(1, 0));
	gunVAO->addVertex(&data);
	data.pos = vec2(1, 1);
	data.tex = textureMap->getTexCoord(vec2(1, 1));
	gunVAO->addVertex(&data);
	data.pos = vec2(1, 1);
	data.tex = textureMap->getTexCoord(vec2(1, 1));
	gunVAO->addVertex(&data);
	data.pos = vec2(0, 1);
	data.tex = textureMap->getTexCoord(vec2(0, 1));
	gunVAO->addVertex(&data);
	data.pos = vec2(0, 0);
	data.tex = textureMap->getTexCoord(vec2(0, 0));
	gunVAO->addVertex(&data);
	gunVAO->unmap();
}

Gun::~Gun() {
	delete gunVAO;
}

void Gun::update(float deltaTime) {
        
}

void Gun::render() {
	//gunVAO->getPos() = player->getPos();

	//gunVAO->render();
}
