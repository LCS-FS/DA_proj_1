#ifndef PROJ1_ALGORITHMS_H
#define PROJ1_ALGORITHMS_H

#include <vector>
#include <iostream>
#include "Van.h"
#include "Delivery.h"
#include "Combination.h"
#include <algorithm>
#include <string>

using std::vector;

vector<vector<vector<int>>> knapsack(vector<Delivery> deliveries, Van van);
vector<Combination> cenario2(vector<Van> vans, vector<Delivery> deliveries);
vector<Combination> cenario1(vector<Van> vans, vector<Delivery> deliveries);
bool sortByPWeightVolume(const Delivery &d1, const Delivery &d2);
bool sortByCost(const Van &v1, const Van &v2);

#endif //PROJ1_ALGORITHMS_H
