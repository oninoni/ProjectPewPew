#pragma once
class Gun {
private:
	Player* player; 
	TextureMap* textureMap;

    InputManager* input;
    FGGrid* grid;

	VAO* gunVAO;
    VAO* beamVAO;
public:
	Gun(Game* g, Player* p);
	~Gun();

	void update(float deltaTime);
	void render();
};

