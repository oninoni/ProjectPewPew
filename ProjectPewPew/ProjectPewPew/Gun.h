#pragma once
class Gun {
private:
	Player* player; 
	TextureMap* textureMap;

    InputManager* input;
    FGGrid& grid;

	VAO* gunVAO;
    VAO* beamVAO;

    void setBeamVAO(vec2 direction, float length, float width, float r, float g, float b, float a);
public:
	Gun(Game* g, Player* p);
	~Gun();

	void update(float deltaTime);
	void render();
};

