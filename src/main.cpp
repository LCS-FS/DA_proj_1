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
    if (!loadVans(vans))
        cout << "loading vans failed" << endl;
    if (!loadDeliveries(deliveries))
        cout << "loading deliveries failed" << endl;
    cout << "made " << firstFitIncreasingCen3(deliveries).size() << " deliveries today.";

    return 0;
}

bool loadVans(vector<Van> &vans) {
    ifstream file;
    file.open("/home/jpdat/Documents/FEUP/2Ano2Semestre/DA/DA_proj_1/src/carrinhas.txt");
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
    file.open("/home/jpdat/Documents/FEUP/2Ano2Semestre/DA/DA_proj_1/src/encomendas.txt");
    if(!file.is_open()) return false; //file didnt open, perhaps not found

    string throwaway;
    int volume, weight, reward, duration;
    file >> throwaway >> throwaway >> throwaway >> throwaway; //throaway first line;

    while(file >> volume >> weight >> reward >> duration){
        deliveries.push_back(Delivery(volume, weight, reward, duration)); //create delivery object from file and add it to vector
    }
    return true;
}
