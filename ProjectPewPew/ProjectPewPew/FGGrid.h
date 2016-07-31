#pragma once
class FGGrid : public BGGrid
{
public:
    FGGrid();
    ~FGGrid();

	void update(double deltaT);
	void render();
};

