#include "Delivery.h"

int Delivery::getVolume() const {
    return volume;
}

void Delivery::setVolume(int volume) {
    Delivery::volume = volume;
}

int Delivery::getWeight() const {
    return weight;
}

void Delivery::setWeight(int weight) {
    Delivery::weight = weight;
}

int Delivery::getReward() const {
    return reward;
}

void Delivery::setReward(int reward) {
    Delivery::reward = reward;
}

int Delivery::getDuration() const {
    return duration;
}

void Delivery::setDuration(int duration) {
    Delivery::duration = duration;
}
