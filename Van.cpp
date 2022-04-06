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

Van::Van(int volume, int weight, int cost) : volume(volume), weight(weight), cost(cost), number(0), value(0) {}

int Van::getNumber() const {
    return number;
}

void Van::setNumber(int number) {
    Van::number = number;
}

int Van::getValue() const {
    return value;
}

void Van::setValue(int value) {
    Van::value = value;
}
