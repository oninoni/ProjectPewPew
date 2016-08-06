#include "stdafx.h"

Cursor::Cursor(Game* g, Player* player) 
{
	window = g->getWindow();
	this->player = player;
    input = player->getInputManager();

	vaoLaser = new VAO(g->getLaserShader()); 
	vaoLaser->generate(6, buDynamicDraw);    

	vaoCrosshair = new VAO(g->getTextureShader());
    vaoCrosshair->generate(6, buStaticDraw);
    vaoCrosshair->getPos().setOffset(vec2(-0.5f, -0.5f));
    
    TextureMap* textureMap = g->getTextureMap();
    textureMap->setTexture("crosshair");
    struct {
        vec2 pos;
        texcoord tex;
        texcoord minborder;
        texcoord maxborder;
    } data;

    data.minborder = textureMap->getMinBorder();
    data.maxborder = textureMap->getMaxBorder();

    vaoCrosshair->map(baWriteOnly);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    vaoCrosshair->addVertex(&data);
    data.pos = vec2(1, 0);
    data.tex = textureMap->getTexCoord(vec2(1, 0));
    vaoCrosshair->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    vaoCrosshair->addVertex(&data);
    data.pos = vec2(1, 1);
    data.tex = textureMap->getTexCoord(vec2(1, 1));
    vaoCrosshair->addVertex(&data);
    data.pos = vec2(0, 1);
    data.tex = textureMap->getTexCoord(vec2(0, 1));
    vaoCrosshair->addVertex(&data);
    data.pos = vec2(0, 0);
    data.tex = textureMap->getTexCoord(vec2(0, 0));
    vaoCrosshair->addVertex(&data);
    vaoCrosshair->unmap();
}

Cursor::~Cursor() 
{
    delete vaoLaser;  // immer muss ich hinter dir aufräumen...
    delete vaoCrosshair; // schreib doch einfach gleich das delete dazu wenn du new schreibst .-.
}

void Cursor::render() 
{      
    vaoCrosshair->getPos().setPosition(input->getGridMousePos());
    vaoCrosshair->render();

    //cout << xPos << "/" << yPos << endl;

	/*vec2 points[4];

	points[0] = player->getPos();

	struct {
		vec2 pos;
		vec2 tex;
		float r, g, b, a;
	} data;

	vaoLaser->map(baWriteOnly);
	vaoLaser->
	vaoLaser->unmap();

	vaoLaser->render();
	vaoTarget->render();*/
}
