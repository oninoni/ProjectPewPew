#include "stdafx.h"

Gun::Gun(Game * g, Player* p) {
	player = p;
	textureMap = g->getTextureMap();

	gunVAO = new VAO(g->getTextureShader());
	gunVAO->generate(6, buDynamicDraw);

	textureMap->setTexture("laser_gun");
	
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

Gun::~Gun() 
{
	delete gunVAO; // I'm so proud of you!
}

void Gun::update(float deltaTime) 
{
    gunVAO->getPos() = player->getPos();
    gunVAO->getPos().setOffset(gunVAO->getPos().getOffset() + vec2(0.0f, 0.3f));
}

void Gun::render() 
{
	gunVAO->render();
}
