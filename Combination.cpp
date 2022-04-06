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
