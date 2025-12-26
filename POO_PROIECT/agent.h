//
// Created by HP-15S on 12/23/2025.
//

#ifndef AGENT_H
#define AGENT_H

#include "map.h"
#include "package.h"
#include <memory>

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

enum class Agents {
    DRONE,
    ROBOT,
    SCOOTER
};

class Agent {
protected:
    int speed;
    int maxBattery;
    int currentBattery;
    int consumptionPerTick;
    int cost;
    int capacity;

    char simbol;

    Position agentPosition;
    StateMachine currentState;
    MovementType movementType;

public:
    Agent(): speed(0),
    maxBattery(100),
    currentBattery(100),
    consumptionPerTick(2),
    cost(1),
    capacity(1),
    agentPosition(basePosition),
    movementType(GROUND),
    currentState(IDLE){}
    virtual ~Agent() = default;

    virtual void actionPerTick(const Map &map);

    char getSimbol() const;
    virtual char *getName() const = 0;

    bool isDead()const;

};


class Drone: public Agent {
public:
    Drone(Position basePosition);
    ~Drone() override = default;

    char *getName() const override;
};


class Robot: public Agent {
public:
    Robot(Position basePosition);
    ~Robot() override = default;

    char *getName() const override;
};


class Scooter: public Agent {
public:
    Scooter(Position basePosition);
    ~Scooter() override = default;

    char *getName() const override;
};

class AgentFactory {
public:
    static std::unique_ptr<Agent> createAgent(Agents agentType, Position initPosition);
};

#endif //AGENT_H

