#include "Van.h"

/// \file
/// Van class functions

/// Volume getter.
/// Returns the value of a delivery
int Van::getVolume() const {
    return volume;
}

/// Van volume setter. Stores the value passed to it by parameter in the volume attribute
/// \param volume
void Van::setVolume(int volume) {
    this->volume = volume;
}

/// Weight getter.
/// Returns the weight of a delivery
int Van::getWeight() const {
    return weight;
}

/// Delivery weight setter. Stores the value passed to it by parameter in the weight attribute
/// \param weight
void Van::setWeight(int weight) {
    this->weight = weight;
}

/// Cost getter.
/// Returns the cost of a delivery
int Van::getCost() const {
    return cost;
}

/// Delivery cost setter. Stores the value passed to it by parameter in the cost attribute
/// \param cost
void Van::setCost(int cost) {
    this->cost = cost;
}

/// Van class constructor
/// \param volume
/// \param weight
/// \param reward
/// \param duration
Van::Van(int volume, int weight, int cost) : volume(volume), weight(weight), cost(cost) {}

bool const Van::operator==(const Van &v2) const {
    if(volume == v2.getVolume() && weight == v2.getWeight() && cost == v2.getCost()) return true;
    return false;
}

/// Van Operator <
/// Returns whether the value of the volume of a combination is less than the one passed as parameter
/// \param v2
bool const Van::operator<(const Van &v2) const {
    if(weight == v2.getWeight()) return volume < v2.getVolume();
    return weight < v2.getWeight();
}

