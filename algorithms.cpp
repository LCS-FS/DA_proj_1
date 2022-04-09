#include "algorithms.h"

Combination multiple_bi_01_knapsack(vector<Van> &vans, vector<Delivery> &deliveries){
    vector<vector<vector<int>>> table;
    vector<Combination> regardless;
    vector<Delivery> chosen;

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

    std::sort(regardless.begin(), regardless.end()); //sort by total value (or number of deliveries if value == 1)
    return regardless[regardless.size()-1]; //return combination with highest value
}

vector<vector<vector<int>>> knapsack(vector<Delivery> deliveries, Van van){
    int maxW = van.getWeight(), maxV = van.getVolume(), n = deliveries.size();
    int current, last;
    //start the cube all as 0s
    vector<vector<vector<int>>> table(n+1, vector<vector<int>>(maxW+1, vector<int>(maxV+1)));

    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= maxW; w++){
            for(int v = 0; v <= maxV; v++){
                //if delivery i is heavier than the chosen weight, the cell will stay the same as the previous cell
                if(deliveries[i-1].getWeight() > w) table[i][w][v] = table[i-1][w][v];
                //if delivey i has higher volume than the chosen volume, the cell will stay the same as the previous cell
                else if(deliveries[i-1].getVolume() > v) table[i][w][v] = table[i-1][w][v];
                else{
                    last = table[i-1][w][v]; //previous value
                    current = table[i-1][w - deliveries[i-1].getWeight()][v - deliveries[i-1].getVolume()] + deliveries[i-1].getReward(); //valor atual + valor que caiba
                    table[i][w][v] = std::max(last, current);
                }
            }
        }
    }
    return table;
}

vector<Combination> cenario1(vector<Van> vans, vector<Delivery> deliveries) {
    vector<Combination> ret;
    vector<Van> auxV;
    vector<Delivery> auxD;
    int progress = 1;
    std::cout << "It Starts slow but gets faster as it goes on.\n";
    std::cout << "Progress: [" << std::string(50, '-') << "] " << "0%\n";


    //set all rewards to 1, so that total value is the number of deliveries in a van
    for (int i = 0; i < deliveries.size(); i++){
        deliveries[i].setReward(1);
    }

    for(int i = 0; i < vans.size(); i++){
        //best combination with considering all vans and deliveries that havent been used so far
        Combination best = multiple_bi_01_knapsack(vans, deliveries);

        auxV.clear();
        auxD.clear();

        //remove chosen van from poll of available vans
        for(auto van:vans){
            if(!(van == best.getVan())) auxV.push_back(van);
        }
        vans = auxV;

        //removed chosen deliveries from poll of available deliveries
        for(auto d1 :deliveries){
            if(std::find(best.getDeliveries().begin(), best.getDeliveries().end(), d1) == best.getDeliveries().end()) auxD.push_back(d1);
        }

        deliveries = auxD;

        ret.push_back(best);
        std::cout << "Progress: [" << std::string(progress, '#') << std::string(50-progress, '-') << "] " << progress*2 << "%\n";
        progress++;
    }
    std::cout << "Progress: [" << std::string(50, '#') << "] 100%\n";

    int value = 1;
    for(auto comb : ret){
        value += comb.getValue();
    }
    std::cout << "number of vans " << ret.size();
    std::cout << "number of items " << value;
    return ret;
}
