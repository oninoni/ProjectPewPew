#pragma once
class Tile {
private:
	int xPos;
	int yPos;

	string textureID;
public:
	Tile(int x, int y, string texID);
	~Tile();

	void addtoVAO(VAO vao);
};

