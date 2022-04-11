#ifndef PROJ1_COMBINATION_H
#define PROJ1_COMBINATION_H

#include <vector>
#include "Van.h"
#include "Delivery.h"

class Combination {
private:
    Van van;
    std::vector<Delivery> deliveries;
    int value;
public:
    Combination(const Van &van, const std::vector<Delivery> &deliveries, int value);
    int getValue() const;
    void setValue(int value);
    const Van &getVan() const;
    void setVan(const Van &van);
    const std::vector<Delivery> &getDeliveries() const;
    void setDeliveries(const std::vector<Delivery> &deliveries);
    void addDelivery(Delivery delivery);
    bool const operator<(const Combination &c2) const;
    bool const operator==(const Combination &c2) const;
};


#endif //PROJ1_COMBINATION_H
