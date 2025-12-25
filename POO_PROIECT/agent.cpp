//
// Created by HP-15S on 12/23/2025.
//

#include <iostream>

#include "agent.h"

using namespace std;

//agent
bool Agent::isDead() const {
    return this->currentState == DEAD;
}

void Agent::actionPerTick(const Map &map) {
    if (this->currentState == DEAD) {
        return;
    }

    if (this->currentState == IDLE) {
        this->currentBattery += this->maxBattery / 4;
    }

    if (this->currentState == CHARGING) {
        this->currentBattery += this->maxBattery / 4;
    }

    if (this->currentState == MOVING) {
        this->currentBattery -= this->consumptionPerTick;

        if (this->currentBattery <= 0) {
            this->currentState = DEAD;
            this->currentBattery = 0;
        }

        if (map.grid[basePosition.getPositionX()][basePosition.getPositionY()] == 'S' || map.grid[basePosition.getPositionX()][basePosition.getPositionY()] == 'B') {
            this->currentState = CHARGING;
        }
    }
}

char Agent::getSimbol() const {
    return this->simbol;
}

std::unique_ptr<Agent> AgentFactory::createAgent(Agents agentType, Position initPosition) {
    switch (agentType) {
        case Agents::DRONE: return std::make_unique<Drone>(initPosition);
        case Agents::ROBOT: return make_unique<Robot>(initPosition);
        case Agents::SCOOTER: return make_unique<Scooter>(initPosition);
        //+++++++++++++++default cu exceptie
    }
}


//drona
Drone::Drone(Position basePosition) {
    this->speed = 3;
    this->maxBattery = 100;
    this->currentBattery = 100;
    this->consumptionPerTick = 10;
    this->cost = 15;
    this->capacity = 1;

    this->simbol = '^';

    this->currentState = IDLE;
    this->movementType = AIR;
}

char* Drone::getName()const{
    return (char *)"Drona";
}


//robot
Robot::Robot(Position basePosition) {
    this->speed = 1;
    this->maxBattery = 300;
    this->currentBattery = 300;
    this->consumptionPerTick = 2;
    this->cost = 1;
    this->capacity = 4;

    this->simbol = 'R';

    this->currentState = IDLE;
    this->movementType = GROUND;
}

char* Robot::getName()const {
    return (char *)"Robot";
}


//scuter
Scooter::Scooter(Position basePosition) {
    this->speed = 2;
    this->maxBattery = 200;
    this->currentBattery = 200;
    this->consumptionPerTick = 5;
    this->cost = 4;
    this->capacity = 2;

    this->simbol = 'S';

    this->currentState = IDLE;
    this->movementType = GROUND;
}

char* Scooter::getName()const {
    return (char *)"Scooter";
}