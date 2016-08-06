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
    delete vaoLaser;
    delete vaoCrosshair;
}

void Cursor::updateLaser() {
	vec2 points[4];

	vec2 direction = (input->getGridMousePos() - player->getPos().getPosition());

	points[0] = -direction.cross().normalize() / 10.0f;
	points[1] = points[0] + direction;
	points[3] = direction.cross().normalize() / 10.0f;
	points[2] = points[3] + direction;

	float length = direction.length();

	cout << "Direction: X= " << direction.x << " / Y= " << direction.y << endl;

	struct {
		vec2 pos;
		vec2 vtexcoord;
		float r, g, b, a;
	} data;

	data.r = 1.0f;
	data.g = 0.0f;
	data.b = 0.0f;
	data.a = 1.0f;

	vaoLaser->map(baWriteOnly);
	data.pos = points[0];
	data.vtexcoord = vec2(-1, 0);
	cout << "0,0: X= " << data.pos.x << " / Y= " << data.pos.y << endl;
	vaoLaser->addVertex(&data);
	data.pos = points[1];
	data.vtexcoord = vec2(-1, length);
	vaoLaser->addVertex(&data);
	data.pos = points[2];
	data.vtexcoord = vec2(1, length);
	vaoLaser->addVertex(&data);
	data.pos = points[2];
	data.vtexcoord = vec2(1, length);
	vaoLaser->addVertex(&data);
	data.pos = points[3];
	data.vtexcoord = vec2(1, 0);
	vaoLaser->addVertex(&data);
	data.pos = points[0];
	data.vtexcoord = vec2(-1, 0);
	vaoLaser->addVertex(&data);
	vaoLaser->unmap();
}

void Cursor::render()
{      
    vaoCrosshair->getPos().setPosition(input->getGridMousePos());
    vaoCrosshair->render();

	updateLaser();
	vaoLaser->render();
}
