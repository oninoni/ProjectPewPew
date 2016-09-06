#pragma once
class Tile {
private:
    ivec2 pos;
	TextureMap* textureMap;
	string texture;

	bool solid;
    bool transparent;
public:
    Tile(ivec2 pos, string texture, Game* g, bool s = false, bool t = false);
	~Tile();

	void addToVAO(VAO* vao);

	string getTexture();
	bool isSolid();
};