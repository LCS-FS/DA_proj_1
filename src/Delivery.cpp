#include "Delivery.h"

int Delivery::getVolume() const {
    return volume;
}

void Delivery::setVolume(int volume) {
    this->volume = volume;
}

int Delivery::getWeight() const {
    return weight;
}

void Delivery::setWeight(int weight) {
    this->weight = weight;
}

int Delivery::getReward() const {
    return reward;
}

void Delivery::setReward(int reward) {
    this->reward = reward;
}

int Delivery::getDuration() const {
    return duration;
}

void Delivery::setDuration(int duration) {
    this->duration = duration;
}

Delivery::Delivery(int volume, int weight, int reward, int duration) : volume(volume), weight(weight), reward(reward),
                                                                       duration(duration) {}

bool const Delivery::operator==(const Delivery &d2) const {
    if(volume == d2.getVolume() && weight == d2.getWeight() && reward == d2.getReward() && duration == d2.getDuration()) return true;
    return false;
}
