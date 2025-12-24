//
// Created by HP-15S on 12/23/2025.
//

#ifndef AGENT_H
#define AGENT_H

#include "map.h"

enum StateMachine {
    IDLE,
    MOVING,
    CHARGING,
    DEAD
};

enum MovementType {
    AIR,
    GROUND
};

class Agent {
protected:
    int speed;
    int maxBattery;
    int currentBattery;
    int consumptionPerTick;
    int cost;
    int capacity;

    int coordX;
    int coordY;

    char simbol;

    StateMachine currentState;
    MovementType movementType;

public:
    Agent(): speed(0),
    maxBattery(100),
    currentBattery(100),
    consumptionPerTick(2),
    cost(1),
    capacity(1),
    movementType(GROUND),
    currentState(IDLE){}
    virtual ~Agent() = default;

    virtual void actionPerTick(const Map &map);

    virtual char getSimbol() const = 0;
    virtual char *getName() const = 0;

    bool isDead()const;

};


class Drone: public Agent {
public:
    Drone();
    ~Drone() override = default;

    char getSimbol() const override;
    char *getName() const override;
};


class Robot: public Agent {
public:
    Robot();
    ~Robot() override = default;

    char getSimbol() const override;
    char *getName() const override;
};


class Scooter: public Agent {
public:
    Scooter();
    ~Scooter() override = default;

    char getSimbol() const override;
    char *getName() const override;
};

#endif //AGENT_H

