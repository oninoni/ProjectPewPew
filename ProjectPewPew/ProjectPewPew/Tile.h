#pragma once

enum TileProperty {
    tpSolid,
    tpTransparent,
    tpDestructible,

    // add new above
    TP_SIZE
};

class Properties {
private:
    vector<bool> properties;           
public:
    Properties();

    bool is(TileProperty prop);
    void set(TileProperty prop);
    void clear(TileProperty prop); 

    void clearAll(TileProperty prop);
};

class TileData {
protected:        
    string texture;

public:
    TileData(string texture);

    Properties properties;
    string getTexture(); 

    void assign(TileData &other);
};

class Tile : public TileData {
private:
    ivec2 pos;
    TextureMap* textureMap;
	
public:
    Tile(ivec2 pos, string texture, Game* g);
	~Tile();

	void addToVAO(VAO* vao);   	   
};