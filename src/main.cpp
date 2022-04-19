#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Van.h"
#include "Delivery.h"
#include "algorithms.h"
#include "Combination.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;

bool loadVans(vector<Van> &vans);
bool loadDeliveries(vector<Delivery> &deliveries);

int main() {
    vector<Van> vans;
    vector<Delivery> deliveries;
    loadVans(vans);
    loadDeliveries(deliveries);

    vector<Combination> c1 = cenario1(vans, deliveries);
    //vector<Combination> c2 = cenario2(vans, deliveries);
    return 0;
}

bool loadVans(vector<Van> &vans) {
    ifstream file;
    file.open("/home/lucas/Dropbox/Universidade/2-2/DA/proj1/input/carrinhas.txt");
    if(!file.is_open()) return false; //file didnt open, perhaps not found

    string throwaway;
    int volume, weight, cost;
    file >> throwaway >> throwaway >> throwaway; //throaway first line;

    while(file >> volume >> weight >> cost){
        vans.push_back(Van(volume, weight, cost)); //create van object from file and add it to vector
    }
    return true;
}

bool loadDeliveries(vector<Delivery> &deliveries) {
    ifstream file;
    file.open("/home/lucas/Dropbox/Universidade/2-2/DA/proj1/input/encomendas.txt");
    if(!file.is_open()) return false; //file didnt open, perhaps not found

    string throwaway;
    int volume, weight, reward, duration;
    file >> throwaway >> throwaway >> throwaway >> throwaway; //throaway first line;

    while(file >> volume >> weight >> reward >> duration){
        deliveries.push_back(Delivery(volume, weight, reward, duration)); //create delivery object from file and add it to vector
    }
    return true;
}
