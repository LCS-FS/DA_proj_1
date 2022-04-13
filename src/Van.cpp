#include "Van.h"

int Van::getVolume() const {
    return volume;
}

void Van::setVolume(int volume) {
    this->volume = volume;
}

int Van::getWeight() const {
    return weight;
}

void Van::setWeight(int weight) {
    this->weight = weight;
}

int Van::getCost() const {
    return cost;
}

void Van::setCost(int cost) {
    this->cost = cost;
}

Van::Van(int volume, int weight, int cost) : volume(volume), weight(weight), cost(cost) {}

bool const Van::operator==(const Van &v2) const {
    if(volume == v2.getVolume() && weight == v2.getWeight() && cost == v2.getCost()) return true;
    return false;
}

