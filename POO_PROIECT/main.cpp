#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.h"
#include "package.h"

using namespace std;

int main() {
    srand(time(NULL));

    Map map;
    map.rows = 10;      // setăm dimensiuni simple
    map.columns = 10;

    ProceduralMapGenerator generator;
    bool ok=false;
    while (!ok) {
        generator.loadMap(map);
        cout<<ok<<" ";
        ok=MapValidator::validateMap(map);
        cout<<ok<<"\n";
    }


    cout << "Harta generata:" << endl;

    for (int i = 0; i < map.rows; i++) {
        for (int j = 0; j < map.columns; j++) {
            char c = '.';

            switch(map.grid[i][j]) {
                case SPACE: c = '.'; break;
                case WALL: c = '#'; break;
                case HUB: c = 'B'; break;
                case STATION: c = 'S'; break;
                case DESTINATION: c = 'D'; break;
            }

            cout << c << " ";
        }
        cout << endl;
    }

    cout<<basePosition.getPositionX()<<"    "<<basePosition.getPositionY()<<endl;

    return 0;
}
