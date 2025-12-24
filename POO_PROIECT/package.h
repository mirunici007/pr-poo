//
// Created by HP-15S on 12/24/2025.
//

#ifndef PACKAGE_H
#define PACKAGE_H


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

extern Position basePosition(0,0);

class Package {
    Position destPosition;

    int reward;
    int deadline;
    int currentTick;
    int spawnTick;

    bool late;
    bool delivered;

    public:
    Package(): destPosition(basePosition.getPositionX(),
                       basePosition.getPositionY()) {
        this->reward = 200 + rand() % 601;
        this->deadline = 10+ rand() % 11;

        this->late = false;
        this->delivered = false;

    }

    ~Package() = default;

    void markDelivered();
    void markLate();
    bool checkLate();
};

#endif //PACKAGE_H
