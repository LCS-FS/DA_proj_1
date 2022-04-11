//
// Created by lcsfe on 06/04/2022.
//

#include "Combination.h"

const Van &Combination::getVan() const {
    return van;
}

void Combination::setVan(const Van &van) {
    Combination::van = van;
}

const std::vector<Delivery> &Combination::getDeliveries() const {
    return deliveries;
}

void Combination::setDeliveries(const std::vector<Delivery> &deliveries) {
    Combination::deliveries = deliveries;
}

void Combination::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}

int Combination::getValue() const {
    return value;
}

void Combination::setValue(int value) {
    Combination::value = value;
}

Combination::Combination(const Van &van, const std::vector<Delivery> &deliveries, int value) : van(van),
                                                                                               deliveries(deliveries),
                                                                                               value(value) {}

bool const Combination::operator<(const Combination &c2) const {
    return value < c2.getValue();
}

bool const Combination::operator==(const Combination &c2) const {
    return van == c2.getVan() && deliveries == c2.getDeliveries() && value == c2.getValue();
}
