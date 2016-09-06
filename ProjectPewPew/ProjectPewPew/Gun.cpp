#include "stdafx.h"

Gun::Gun(Game * g, Player* p) {
	player = p;
	textureMap = g->getTextureMap();
    
    input = p->getInputManager();
    grid = g->getFGGrid();

    beamVAO = new VAO(g->getLaserShader());
    beamVAO->generate(6, buDynamicDraw);

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

    if (input->keyDown(kaFirePrimary)) {
        vec2 points[4];

        vec2 direction = player->getPos().getPosition().vectorTo(input->getGridMousePos());

        RayCaster rayCaster(grid->getSize(), player->getPos().getPosition(), direction);

        float lastDistance = -1;

        while (rayCaster.next()) {
            if (grid->getTileAt(rayCaster.getTilePos()).isSolid()) {
                if (input->keyPressed(kaFirePrimary)) {
                    grid->destroyTileAt(rayCaster.getTilePos());
                    rayCaster.next();
                }
                lastDistance = rayCaster.getDistance();
                break;
            }
        }

        if (lastDistance == -1)
            lastDistance = rayCaster.getDistance();

        points[0] = player->getPos().getPosition() - direction.cross().normalize() / 25.0f;
        points[1] = points[0] + direction.normalize() * lastDistance;
        points[3] = player->getPos().getPosition() + direction.cross().normalize() / 25.0f;
        points[2] = points[3] + direction.normalize() * lastDistance;

        struct {
            vec2 pos;
            vec2 vtexcoord;
            float r, g, b, a;
        } data;

        data.r = 0.0f;
        data.g = 1.0f;
        data.b = 0.0f;
        data.a = 1.0f;

        beamVAO->map(baWriteOnly);
        data.pos = points[0];
        data.vtexcoord = vec2(-1, 0);
        beamVAO->addVertex(&data);
        data.pos = points[1];
        data.vtexcoord = vec2(-1, 1);
        beamVAO->addVertex(&data);
        data.pos = points[2];
        data.vtexcoord = vec2(1, 1);
        beamVAO->addVertex(&data);
        data.pos = points[2];
        data.vtexcoord = vec2(1, 1);
        beamVAO->addVertex(&data);
        data.pos = points[3];
        data.vtexcoord = vec2(1, 0);
        beamVAO->addVertex(&data);
        data.pos = points[0];
        data.vtexcoord = vec2(-1, 0);
        beamVAO->addVertex(&data);
        beamVAO->unmap();
    }
}

void Gun::render() 
{
    if (input->keyDown(kaFirePrimary)) {
        beamVAO->render();
    }
	gunVAO->render();
}
