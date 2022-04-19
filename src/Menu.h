//
// Created by jpdat on 19-04-2022.
//

#ifndef PROJ1_MENU_H
#define PROJ1_MENU_H4

#include <string>
#include <iostream>
#include "algorithms.h"

using namespace std;

class Menu {
    const string firstDisplay = "Welcome to the package delivery interface. Please select the desired scenario\n";
    const string scenarioOptions = "1 - Fitting packages in least vans (Scenario 1)\n"
                             "2 - Most profitable distribution (Scenario 2)\n"
                             "3 - Lesser delivery time (Scenario 3)\n";
    const string invalidInput = "That input is not valid!\n"
                                "Please try again!\n";
    vector<Van> vans;
    vector<Delivery> deliveries;

public:
    Menu();
    ~Menu();
    int intInput(int min, int max);
    void run();
};




#endif //PROJ1_MENU_H
