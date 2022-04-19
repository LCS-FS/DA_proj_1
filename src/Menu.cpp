//
// Created by jpdat on 19-04-2022.
//

#include "Menu.h"

using namespace std;

int Menu::intInput(int min, int max) {
    string input;
    int output;
    cin >> input;
    try {
        output = stoi(input);
    } catch (invalid_argument &e) {
        cout << invalidInput;
        return -1;
    }
    if (output < min || output > max) {
        cout << invalidInput;
        return -1;
    }
    return output;
}

int Menu::run() {
    int option;

    cout << firstDisplay;
    cout << scenarioOptions;

    do {
      option = intInput(1, 4);
    } while (option == -1);

    switch (option) {
        case 1:
             cenario1(vans, deliveries);
            break;
        case 2:
             cenario2(vans, deliveries);
            break;
        case 3:
            cout << "Made " << firstFitIncreasingCen3(deliveries).size() << " deliveries today." << endl;
            break;
        default:
            return 0;
    }
    return 1;
}

Menu::Menu() {
    if (!loadVans(vans))
        cout << "failed loading vans" << endl;
    if (!loadDeliveries(deliveries))
        cout << "failed loading deliveries" << endl;
}

Menu::~Menu() = default;
