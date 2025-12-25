#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.h"
#include "package.h"

using namespace std;
#include "config.h"

int main() {
    srand(time(NULL));

    Map map;
    //map.rows = 20;      // setăm dimensiuni simple
    //map.columns = 20;

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

    try {
        // Încarcă config (cu fallback automat)
        ConfigFile& config = ConfigFile::getInstance();

        try {
            config.loadFromFile("simulation_setup.txt");
        } catch (const std::exception& e) {
            std::cerr << "Folosesc config default" << std::endl;
        }

        config.printConfig();
    }catch (const std::exception& e) {
        std::cerr << "EROARE:  " << e.what() << std::endl;
        throw;
    }
    return 0;
}
