//
// Created by HP-15S on 12/23/2025.
//

#ifndef MAP_H
#define MAP_H

#include "config.h"

enum CellRole {
    SPACE,
    WALL,
    HUB,
    STATION,
    DESTINATION
};

class Map {
public:
    int rows;
    int columns;
    int nrClients;
    int nrStations;
    CellRole grid[100][100] = {SPACE};

    Map(int row = 20, int col = 20, int clients = 10, int stations = 3);
    ~Map() = default;
};

class MapStrategy {
public:
    virtual void loadMap(Map &map) = 0;
    virtual ~MapStrategy() = default;
};

class FileMapLoader: public MapStrategy {
    const char *fileName;

public:
    FileMapLoader(const char *file): fileName(file){}
    ~FileMapLoader() override = default;

    void loadMap(Map &map)override;
};

class ProceduralMapGenerator: public MapStrategy {
public:
    ~ProceduralMapGenerator() override = default;
    void loadMap(Map &map)override;
};

class MapValidator {
public:
    static bool validateMap(Map &map);
};

#endif //MAP_H