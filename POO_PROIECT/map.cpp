//
// Created by HP-15S on 12/23/2025.
//

#include <iostream>
#include <sstream>
#include <random>

#include "map.h"

using namespace std;

void FileMapLoader::loadMap(Map &map) {
    FILE *file = fopen(fileName, "r");

    if (!file) {
        cerr<<"Nu s-a putut deschide fisierul!";
        exit(1);
    }

    fscanf(file, "%d %d", &map.rows, &map.columns);

    for (int i = 0; i < map.rows; i++) {
        for (int j = 0; j < map.columns; j++) {
            char c = fgetc(file);

            switch (c) {
                case '.': map.grid[i][j] = SPACE; break;
                case '#': map.grid[i][j] = WALL; break;
                case 'B': map.grid[i][j] = HUB; break;
                case 'S': map.grid[i][j] = STATION; break;
                case 'D': map.grid[i][j] = DESTINATION; break;
            }
        }
    }

}

void ProceduralMapGenerator::loadMap(Map &map) {
    /*for (int i = 0; i< map.rows; i++) {
        for (int j = 0; j< map.columns; j++) {
            map.grid[i][j] = SPACE;
        }
    }*/

    int hubX = rand() % map.rows;
    int hubY = rand() % map.columns;
    basePosition.setPosition(hubX, hubY);
    map.grid[hubX][hubY] = HUB;

    int stations = map.nrStations;
    while (stations) {
        int randomRow = rand() % map.rows;
        int randomColumn = rand() % map.columns;

        if (map.grid[randomRow][randomColumn] == SPACE) {
            map.grid[randomRow][randomColumn] = STATION;
            stations--;
        }
    }

    int clients = map.nrClients;
    while (clients) {
        int randomRow = rand() % map.rows;
        int randomColumn = rand() % map.columns;

        if (map.grid[randomRow][randomColumn] == SPACE) {
            map.grid[randomRow][randomColumn] = DESTINATION;
            clients--;
        }
    }

    int nrWalls = map.rows * map.columns *0.2;

    while (nrWalls) {
        int randomRow = rand() % map.rows;
        int randomColumn = rand() % map.columns;

        if (map.grid[randomRow][randomColumn] == SPACE) {
            map.grid[randomRow][randomColumn] = WALL;
            nrWalls--;
        }
    }
}

//de vazut pe urma
bool MapValidator::validateMap(Map &map) {
    bool visited[100][100] = {false};

    // coadă simplă pentru BFS
    int queueX[10000], queueY[10000];
    int head = 0, tail = 0;

    //găsește HUB
    for (int i = 0; i < map.rows; i++) {
        for (int j = 0; j < map.columns; j++) {
            if (map.grid[i][j] == HUB) {
                queueX[tail] = i;
                queueY[tail] = j;
                tail++;
                visited[i][j] = true;
            }
        }
    }

    // dacă nu există HUB, harta e invalidă
    if (tail == 0) return false;

    //BFS pentru a marca toate celulele accesibile
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (head < tail) {
        int x = queueX[head];
        int y = queueY[head];
        head++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < map.rows &&
                ny >= 0 && ny < map.columns &&
                map.grid[nx][ny] != WALL &&
                !visited[nx][ny]) {

                visited[nx][ny] = true;
                queueX[tail] = nx;
                queueY[tail] = ny;
                tail++;
                }
        }
    }

    // verifică dacă toate DESTINATION și STATION sunt accesibile
    for (int i = 0; i < map.rows; i++) {
        for (int j = 0; j < map.columns; j++) {
            if ((map.grid[i][j] == DESTINATION || map.grid[i][j] == STATION) &&
                !visited[i][j]) {
                return false;
                }
        }
    }
    // toate punctele importante sunt accesibile
    return true;
}