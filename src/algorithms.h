#ifndef PROJ1_ALGORITHMS_H
#define PROJ1_ALGORITHMS_H

#include <vector>
#include <iostream>
#include "Van.h"
#include "Delivery.h"
#include "Combination.h"
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using std::vector;

vector<vector<vector<int>>> knapsack(vector<Delivery> deliveries, Van van);
vector<Combination> cenario2(vector<Van> vans, vector<Delivery> deliveries);
vector<Combination> cenario1(vector<Van> vans, vector<Delivery> deliveries);
bool sortByPWeightVolume(const Delivery &d1, const Delivery &d2);
bool sortByCost(const Van &v1, const Van &v2);
double compose(int x, int y);
bool compareComposedDelivery(const Delivery &del1, const Delivery &del2);
vector<Delivery> firstFitIncreasingCen3(vector<Delivery> &deliveries);
bool compareTime(const Delivery &del1, const Delivery &del2);
bool loadVans(vector<Van> &vans);
bool loadDeliveries(vector<Delivery> &deliveries);

#endif //PROJ1_ALGORITHMS_H
