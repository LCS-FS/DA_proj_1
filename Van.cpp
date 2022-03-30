#include "Van.h"

int Van::getVolume() const {
    return volume;
}

void Van::setVolume(int volume) {
    Van::volume = volume;
}

int Van::getWeight() const {
    return weight;
}

void Van::setWeight(int weight) {
    Van::weight = weight;
}

int Van::getCost() const {
    return cost;
}

void Van::setCost(int cost) {
    Van::cost = cost;
}
