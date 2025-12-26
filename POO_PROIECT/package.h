//
// Created by HP-15S on 12/24/2025.
//

#ifndef PACKAGE_H
#define PACKAGE_H

#include "config.h"


class Position {
    int positionX;
    int positionY;

public:
    Position(int baseX, int baseY) : positionX(baseX), positionY(baseY) {}
    ~Position() = default;

    void setPosition(int x, int y);

    int getPositionX() const;
    int getPositionY() const;
};

extern Position basePosition;

class Package {
    Position destPosition;

    int id;
    int reward;
    int deadline;
    int currentTick;
    int spawnTick;

    bool late;
    bool delivered;

    public:
    Package(int packageId, Position destPosition);
    ~Package() = default;

    void markDelivered();
    void markLate();
    bool checkLate();
};

#endif //PACKAGE_H
