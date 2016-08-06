#pragma once
class Gun {
private:
	Player* player;

	VAO* gunVAO;
	TextureMap* textureMap;
public:
	Gun(Game* g, Player* p);
	~Gun();

	void update(float deltaTime);
	void render();
};

