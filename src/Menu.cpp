//
// Created by jpdat on 19-04-2022.
//

#include "Menu.h"

using namespace std;

/// \file
/// Menu class functions

/// Function to check whether the character that is passed on the keyboard is valid
/// Returns -1 in case a character is entered that is not a number or that is not within the interval that is passed to it by parameter, and the character in another case
/// \param min. It corresponds to the minimum value that the user can request, that is, to the first possible scenario
/// \param max. It corresponds to the maximum value that the user can request, that is, to the last possible scenario
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

/// Function to run the scenarios. Use the function intInput to find out which option the user has chosen, and run the scenario that corresponds to that number
int Menu::run() {
    int option;

    cout << firstDisplay;
    cout << scenarioOptions;

    do {
      option = intInput(1, 4);
    } while (option == -1);

    switch (option) {
        case 1:
            printCombinations(cenario1(vans, deliveries), false);
            break;
        case 2:
            printCombinations(cenario2(vans, deliveries), true);
            break;
        case 3: {
            vector<Delivery> ret;
            ret = firstFitIncreasingCen3(deliveries);
            for (auto delivery: ret) {
                cout << "Delivery:    Volume: " << delivery.getVolume()
                     << string(8 - to_string(delivery.getVolume()).length(), ' ')
                     << "Weight: " << delivery.getWeight() << string(8 - to_string(delivery.getWeight()).length(), ' ')
                     << "Reward: "
                     << delivery.getReward() << string(8 - to_string(delivery.getReward()).length(), ' ')
                     << "Duration: " << delivery.getDuration() << '\n';
            }
            cout << "\nMade " << ret.size() << " deliveries today." << endl;
            break;
        }
        default:
            return 0;
    }
    return 1;
}

/// Menu class constructor
Menu::Menu() {
    if (!loadVans(vans))
        cout << "failed loading vans" << endl;
    if (!loadDeliveries(deliveries))
        cout << "failed loading deliveries" << endl;
}

/// Menu class destroyer
Menu::~Menu() = default;
