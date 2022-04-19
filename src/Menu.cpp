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

void Menu::run() {
    int option;

    cout << firstDisplay;
    cout << scenarioOptions;

    do {
      option = intInput(1, 3);
    } while (option == -1);

    switch (option) {
        case 1:
            cenario1(vans, deliveries);
            //do something with the result
            break;
        case 2:
            cenario2(vans, deliveries);
            // do something with the result
            break;
        case 3:
            cout << "Made " << firstFitIncreasingCen3(deliveries).size() << " deliveries today." << endl;
            break;
        default:
            break;
    }
}

Menu::Menu() {
    loadVans(vans);
    loadDeliveries(deliveries);
}

Menu::~Menu() = default;
