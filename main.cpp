#include <iostream>#include <fstream>
#include <vector>
#include "Van.h"
#include "Delivery.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

bool loadVans(vector<Van> &vans);
bool loadDeliveries(vector<Delivery> &deliveries);

int main() {
    vector<Van> vans;
    vector<Delivery> deliveries;
    loadVans(vans);
    loadDeliveries(deliveries);
    return 0;
}
