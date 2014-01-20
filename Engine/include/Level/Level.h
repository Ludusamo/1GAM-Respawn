#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include "TileData.h"
#include "Level/Tilemap.h"
#include "Entity/Player.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "AI/AI.h"

#define TILE_SIZE 32
#define SCALE 2.0

class Level {
public:
    Level();
    ~Level();

    void load();
    void loadLevel(const std::string& tilesetFile, const std::string&  file);
    void saveLevel();
    void generateLevel(const std::string& tilesetFile, int widthB, int heightB);
    void unload();
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
    Player &getPlayer();
    std::vector<std::vector<int>> getColMap();

    int getWidth();
    int getHeight();
protected:
private:
    // Map
    int width, height;
    std::vector<int> tiles;
    Tilemap tmap;
    std::vector<std::vector<int>> colMap;
    std::string name;

    // Player
    Player player;
    sf::Texture pTex;
    sf::Texture aiTex;

    // Shader
    sf::Shader shader;
    float ambientIntensity = 1.0f;
    sf::Vector3f ambientColor;

    //TEMP
    AI ai;

    Player p2;
};
#endif // LEVEL_H
