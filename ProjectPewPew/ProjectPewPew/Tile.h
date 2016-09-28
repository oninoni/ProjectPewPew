#pragma once

enum BGTileProperty {
    bpIce,
    bpFire,
    bpSlow,

    // add new above
    BP_SIZE
};

enum FGTileProperty {
    fpSolid,
    fpTransparent,
    fpDestructible,

    // add new above
    FP_SIZE
};

typedef set<BGTileProperty> BGProperties;
typedef set<FGTileProperty> FGProperties;

enum TileType {
    ttGrass
};

class TileData abstract {
public:
    virtual TileType getType() const = 0;
    virtual string getTexture() const = 0;   
    virtual bool isBackground() const = 0;
};

class BGTileData abstract : public TileData {
public:
    virtual BGProperties getProperties() const = 0;
    bool isBackground() const;
};

class FGTileData abstract : public TileData {
public:
    virtual FGProperties getProperties() const = 0;
    bool isBackground() const;
};

class Tile abstract {
protected:
    ivec2 pos;

    TextureMap* textureMap;
    BGGrid* grid;
    
    VAO* vao;

    TileData* data;

    void updateVAO();

public:
    Tile(ivec2 pos, Game* g, VAO* vao, TileData* data);
	~Tile();

    TileData& operator=(TileData &data);
    Tile& operator=(Tile &other); // only copies data

    bool operator==(Tile &other);
    bool operator!=(Tile &other);
};

class BGTile : public Tile {
public:
    BGTile(ivec2 pos, Game* g, VAO* vao, BGTileData* data);
};

class FGTile : public Tile {
public:
    FGTile(ivec2 pos, Game* g, VAO* vao, FGTileData* data);
};