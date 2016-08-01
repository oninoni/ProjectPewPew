#pragma once
class Player
{
private:
    vec2 pos;

public:
    Player(vec2 pos);
    Player(float x, float y);
    ~Player();

	void update(double deltaT);
	void render();
};

