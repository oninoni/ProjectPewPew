#pragma once
class Tile {
private:
    ivec2 pos;
	TextureMap* textureMap;
	string texture;

	bool solid;
    bool transparent;
    bool destructable;
public:
    Tile(ivec2 pos, string texture, Game* g, bool s = false, bool t = true, bool d = true);
	~Tile();

	void addToVAO(VAO* vao);

	string getTexture();
	bool isSolid();
    bool isTransparent();
    bool isDestrucable();
};