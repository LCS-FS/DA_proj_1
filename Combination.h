#ifndef PROJ1_COMBINATION_H
#define PROJ1_COMBINATION_H

#include <vector>
#include "Van.h"
#include "Delivery.h"

class Combination {
private:
    Van van;
    std::vector<Delivery> deliveries;
public:
    const Van &getVan() const;
    void setVan(const Van &van);
    const std::vector<Delivery> &getDeliveries() const;
    void setDeliveries(const std::vector<Delivery> &deliveries);
    void addDelivery(Delivery delivery);
};


#endif //PROJ1_COMBINATION_H
