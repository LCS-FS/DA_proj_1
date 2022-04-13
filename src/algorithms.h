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

using std::vector;

Combination multiple_bi_01_knapsack(vector<Van> &vans, vector<Delivery> &deliveries);
vector<vector<vector<int>>> knapsack(vector<Delivery> deliveries, Van van);
vector<Combination> cenario1(vector<Van> vans, vector<Delivery> deliveries);
vector<Combination> cenario2(vector<Van> vans, vector<Delivery> deliveries);
Combination multiple_bi_01_knapsack_values(vector<Van> &vans, vector<Delivery> &deliveries);
bool sortByProfit(const Combination &c1, const Combination &c2);
double compose(int x, int y);
bool compareComposedDelivery(const Delivery &del1, const Delivery &del2);


#endif //PROJ1_ALGORITHMS_H
