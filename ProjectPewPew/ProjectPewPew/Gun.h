#pragma once
class Gun {
private:
	Player* player;

	VAO* gunVAO;
	TextureMap* textureMap;
public:
	Gun(Game* g);
	~Gun();

	void update(float deltaTime);
	void render();
};

