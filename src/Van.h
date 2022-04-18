#ifndef PROJ1_VAN_H
#define PROJ1_VAN_H

#include "Delivery.h"
#include <vector>

using namespace std;

class Van {
private:
    int volume, weight, cost;
public:
    Van(int volume, int weight, int cost);
    int getVolume() const;
    void setVolume(int volume);
    int getWeight() const;
    void setWeight(int weight);
    int getCost() const;
    void setCost(int cost);
    bool const operator==(const Van &v2) const;
    vector<Delivery> assigned;
};


#endif //PROJ1_VAN_H
