#include "stdafx.h"

Cursor::Cursor(Game* g, Player* player, FGGrid* gr) 
{
	window = g->getWindow();
	this->player = player;
    input = player->getInputManager();

    grid = gr;

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

	vaoCrosshair->getPos().setScale(0.5f);
}

Cursor::~Cursor() 
{
    delete vaoLaser;
    delete vaoCrosshair;
}

vec2 Cursor::getDirection()
{
    return player->getPos().getPosition().vectorTo(input->getGridMousePos());
}

void Cursor::updateLaser() {
	vec2 points[4];

	vec2 direction = getDirection();

    RayCaster rayCaster(grid->getSize(), player->getPos().getPosition(), direction);

    float l = 10.0f;

    while (rayCaster.next()) {
        if (grid->getTileAt(rayCaster.getTilePos()).isSolid()) {
            l = rayCaster.getDistance();
            cout << "Distance detected: " << l << endl;
            break;
        }
    }

    points[0] = player->getPos().getPosition() - direction.cross().normalize() / 25.0f;
    points[1] = points[0] + direction.normalize() * l;
    points[3] = player->getPos().getPosition() + direction.cross().normalize() / 25.0f;
    points[2] = points[3] + direction.normalize() * l;

	struct {
		vec2 pos;
		vec2 vtexcoord;
		float length;
		float r, g, b, a;
	} data;

	data.r = 1.0f;
	data.g = 0.0f;
	data.b = 0.0f;
	data.a = 1.0f;

	data.length = l;

	vaoLaser->map(baWriteOnly);
	data.pos = points[0];
	data.vtexcoord = vec2(-1, 0);
	vaoLaser->addVertex(&data);
	data.pos = points[1];
	data.vtexcoord = vec2(-1, 1);
	vaoLaser->addVertex(&data);
	data.pos = points[2];
	data.vtexcoord = vec2(1, 1);
	vaoLaser->addVertex(&data);
	data.pos = points[2];
	data.vtexcoord = vec2(1, 1);
	vaoLaser->addVertex(&data);
	data.pos = points[3];
	data.vtexcoord = vec2(1, 0);
	vaoLaser->addVertex(&data);
	data.pos = points[0];
	data.vtexcoord = vec2(-1, 0);
	vaoLaser->addVertex(&data);
	vaoLaser->unmap();
}

void Cursor::update(float deltaTime) {
	vaoCrosshair->getPos().rotate(deltaTime * 45);
}



void Cursor::render()
{
	updateLaser();
	vaoLaser->render();

    vaoCrosshair->getPos().setPosition(input->getGridMousePos());
    vaoCrosshair->render();
}
