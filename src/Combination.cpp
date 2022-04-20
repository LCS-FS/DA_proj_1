//
// Created by lcsfe on 06/04/2022.
//

#include "Combination.h"

/// \file
/// Combinations class functions

/// Van getter
/// Returns a van
const Van &Combination::getVan() const {
    return van;
}

/// Van setter. Stores the value passed to it by parameter in the van attribute
/// \param van
void Combination::setVan(const Van &van) {
    Combination::van = van;
}

/// Delivery getter
/// Returns an array of deliveries
const std::vector<Delivery> &Combination::getDeliveries() const {
    return deliveries;
}

/// Deliveries setter. Stores the value passed to it by parameter in the array of deliveries
/// \param van
void Combination::setDeliveries(const std::vector<Delivery> &deliveries) {
    Combination::deliveries = deliveries;
}

/// Function to add a delivery to the array
/// \param van
void Combination::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}

/// Value getter.
/// Returns the value of a combination
int Combination::getValue() const {
    return value;
}

/// Combination value setter. Stores the value passed to it by parameter in the value attribute
/// \param value
void Combination::setValue(int value) {
    Combination::value = value;
}

/// Combinations class constructor
/// \param vanu
/// \param deliveries
/// \param value
Combination::Combination(const Van &van, const std::vector<Delivery> &deliveries, int value) : van(van),
                                                                                               deliveries(deliveries),
                                                                                               value(value) {}

/// Operator <
/// Returns if the value of a combination is less than the one passed as parameter
/// \param c2
bool const Combination::operator<(const Combination &c2) const {
    return value < c2.getValue();
}

/// Combination Operator ==
/// Returns if the attributes of a combination are the same as the one passed as parameter
/// \param c2
bool const Combination::operator==(const Combination &c2) const {
    return van == c2.getVan() && deliveries == c2.getDeliveries() && value == c2.getValue();
}
