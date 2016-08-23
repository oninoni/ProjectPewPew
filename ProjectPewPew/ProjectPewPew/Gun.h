#pragma once
class Gun {
private:
	Player* player; 
	TextureMap* textureMap;

	VAO* gunVAO;
public:
	Gun(Game* g, Player* p);
	~Gun();

	void update(float deltaTime);
	void render();
};

