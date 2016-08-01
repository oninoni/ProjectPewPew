#pragma once
class Tile {
private:
    ivec2 pos;

	string texture;
public:
	Tile(int x, int y, string texture);
    Tile(ivec2 pos, string texture);
	~Tile();

	void addToVAO(VAO vao);
};

