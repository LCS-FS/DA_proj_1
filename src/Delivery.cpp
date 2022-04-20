#include "Delivery.h"

/// \file
/// Delivery class functions

/// Volume getter.
/// Returns the value of a delivery
int Delivery::getVolume() const {
    return volume;
}

/// Delivery volume setter. Stores the value passed to it by parameter in the volume attribute
/// \param volume
void Delivery::setVolume(int volume) {
    this->volume = volume;
}

/// Weight getter.
/// Returns the weight of a delivery
int Delivery::getWeight() const {
    return weight;
}

/// Delivery weight setter. Stores the value passed to it by parameter in the weight attribute
/// \param weight
void Delivery::setWeight(int weight) {
    this->weight = weight;
}

/// Reward getter.
/// Returns the reward of a delivery
int Delivery::getReward() const {
    return reward;
}

/// Delivery reward setter. Stores the value passed to it by parameter in the reward attribute
/// \param reward
void Delivery::setReward(int reward) {
    this->reward = reward;
}

/// Duration getter.
/// Returns the duration of a delivery
int Delivery::getDuration() const {
    return duration;
}

/// Delivery duration setter. Stores the value passed to it by parameter in the duration attribute
/// \param duration
void Delivery::setDuration(int duration) {
    this->duration = duration;
}

/// Delivery class constructor
/// \param volume
/// \param weight
/// \param reward
/// \param duration
Delivery::Delivery(int volume, int weight, int reward, int duration) : volume(volume), weight(weight), reward(reward),
                                                                       duration(duration) {}

/// Operator ==
/// Returns if the attributes of a combination are the same as the one passed as parameter
/// \param d2
bool const Delivery::operator==(const Delivery &d2) const {
    if(volume == d2.getVolume() && weight == d2.getWeight() && reward == d2.getReward() && duration == d2.getDuration()) return true;
    return false;
}
