#include "algorithms.h"
#include <algorithm>


void multiple_bi_01_knapsack(vector<Van> vans, vector<Delivery> deliveries){
    vector<vector<vector<int>>> table;
    vector<Combination> regardless;
    vector<Delivery> chosen;

    //set all rewards to 1, so that total value is the number of deliveries in a van
    for (auto delivery: deliveries){
        delivery.setReward(1);
    }

    //for every van find best combination regardless of other vans
    for(int i = 0; i < vans.size(); i++){
        //make sure chosen is empty
        chosen.clear();
        // do a bidimentional knapsack 0-1
        //table is a cube
        table = knapsack(deliveries, vans[i]);

        //corner cell
        int value = table[deliveries.size()][vans[i].getWeight()][vans[i].getVolume()];
        int w = vans[i].getWeight(), v = vans[i].getVolume(), n = deliveries.size();

        //save the chosen deliveries
        for(int i = n; i > 0; i--){
            if(table[i][w][v] != table[i-1][w][v]){
                chosen.push_back(deliveries[i-1]);
                w -= deliveries[i-1].getWeight();
                v -= deliveries[i-1].getVolume();
            }
        }
        regardless.push_back(Combination(vans[i], chosen, value));
    }

    //TODO continue
}

vector<vector<vector<int>>> knapsack(vector<Delivery> deliveries, Van van){
    int maxW = van.getWeight(), maxV = van.getVolume(), n = deliveries.size();
    int current, last;
    //por o cubo todo a 0s
    vector<vector<vector<int>>> table(n+1, vector<vector<int>>(maxW+1, vector<int>(maxV+1)));


    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= maxW; w++){
            for(int v = 0; v <= maxV; v++){
                //se o item i for mais pesado que o peso escolhido, a celula fica igual á celula anterior
                if(deliveries[i-1].getWeight() > w) table[i][w][v] = table[i-1][w][v];
                    //se o item i for mais volumoso que o volume escolhido, a celula fica igaul á anterior
                else if(deliveries[i-1].getVolume() > v) table[i][w][v] = table[i-1][w][v];
                else{
                    last = table[i-1][w][v]; //valor anterior
                    current = table[i-1][w - deliveries[i-1].getWeight()][v - deliveries[i-1].getVolume()] + deliveries[i-1].getReward(); //valor atual + valor que caiba
                    table[i][w][v] = std::max(last, current);
                }
            }
        }
    }
    return table;
}