#pragma once

// Background Tiles

class TGrass : public BGTileData {
public:
    string getTexture();
    Properties getProperties();
    BGTileType getType();      
};

// Foreground Tiles

class TStone : public FGTileData {
public:
    string getTexture();
    Properties getProperties();
    BGTileType getType();
};