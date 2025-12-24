//
// Created by HP-15S on 12/24/2025.
//
#include <iostream>

#include "package.h"

void Position::setPosition(int x, int y) {
    this->positionX = x;
    this->positionY = y;
}

int Position::getPositionX() const {
    return positionX;
}

int Position::getPositionY() const {
    return positionY;
}


void Package::markDelivered() {
    this->delivered = true;
}
void Package::markLate() {
    this->late = true;
}
bool Package::checkLate() {
    if (this->currentTick - this->spawnTick > this->deadline) {
        this->late = true;
        return true;
    }
    return false;
}