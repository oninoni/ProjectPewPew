#pragma once
class Tile {
private:
    ivec2 pos;
	TextureMap* textureMap;
	string texture;

	boolean solid;
public:
    Tile(ivec2 pos, string texture, Game* g);
	Tile(ivec2 pos, string texture, Game* g, bool s);
	~Tile();

	void addToVAO(VAO* vao);

	string getTexture();
	bool isSolid();
};

