#pragma once
class Tile {
private:
    ivec2 pos;
	TextureMap* textureMap;
	string texture;
public:
	Tile(int x, int y, string texture, Game* g);
    Tile(ivec2 pos, string texture, Game* g);
	~Tile();

	void addToVAO(VAO* vao);
};

