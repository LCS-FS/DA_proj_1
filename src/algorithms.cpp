#include "algorithms.h"
/// \file
/// Algorithms for each scenario and auxiliary functions

/// Algorithm for cenario 1
/// returns a vector of Combinations representing the best distribution of deliveries per van, so that we minimize the number of used vans \n
/// Time Complexity: O(n^2)
/// \param vans
/// \param deliveries
vector<Combination> cenario1(vector<Van> vans, vector<Delivery> deliveries){
    vector<Combination> ret, ret2;
    vector<Delivery> empty;

    //sort deliveries by weight and then volume
    std::sort(deliveries.begin(), deliveries.end(), sortByPWeightVolume);

    //sort vans by weight and then by volume
    std::sort(vans.begin(), vans.end());

    //create combinations with all vans so that indices match
    for(auto van: vans){
        ret.push_back(Combination(van, empty, 0));
    }

    for(int i = 0; i < deliveries.size(); i++){
        //find best van that can accomudate the delivery
        int v = 0;
        for (v; v < vans.size(); v++)
            if(ret[v].getVan().getWeight() >= deliveries[i].getWeight() && ret[v].getVan().getVolume() >= deliveries[i].getVolume()) break;

        //v is now the index for the best van for the item
        int maxV = ret[v].getVan().getVolume(), maxW = ret[v].getVan().getWeight();

        ret[v].addDelivery(deliveries[i]);
        //update weight and volume available to the van
        ret[v].setVan(Van(maxV-deliveries[i].getVolume(), maxW - deliveries[i].getWeight(), 0));
    }

    //count number of deliveries
    int cnt = 0;
    for(auto comb: ret){
        if(comb.getDeliveries().size() !=0){
            ret2.push_back(comb);
            cnt += comb.getDeliveries().size();
        }
    }

    std::cout << "number of vans " << ret2.size() << std::endl;
    std::cout << "number of deliveries " << cnt << std::endl;
    return ret;
}

bool sortByPWeightVolume(const Delivery &d1, const Delivery &d2){
    if(d1.getWeight() == d2.getWeight()) return d1.getVolume() < d2.getVolume();
    return d1.getWeight() < d2.getWeight();
}

//==================================================================================================================================


vector<Combination> cenario2(vector<Van> vans, vector<Delivery> deliveries) {
    vector<Combination> ret;
    vector<Van> auxV;
    vector<Delivery> auxD;
    vector<vector<vector<int>>> table;
    vector<Combination> regardless;
    vector<Delivery> chosen;

    //progress bar
    int progress = 1;
    std::cout << "It Starts slow but gets faster as it goes on.\n";
    std::cout << "Progress: [" << std::string(50, '-') << "] " << "0%\n";

    //sort vans by cost
    std::sort(vans.begin(), vans.end(), sortByCost);

    for(int i = 0; i < vans.size(); i++){
        regardless.clear();
        chosen.clear();

        //0-1 knapsack bidimentional
        table = knapsack(deliveries, vans[i]);

        //get highest value
        int value = table[deliveries.size()][vans[i].getWeight()][vans[i].getVolume()];
        int w = vans[i].getWeight(), v = vans[i].getVolume(), n = deliveries.size();

        //save the chosen deliveries
        for(int k = n; k > 0; k--){
            if(table[k][w][v] != table[k-1][w][v]){
                chosen.push_back(deliveries[k-1]);
                w -= deliveries[k-1].getWeight();
                v -= deliveries[k-1].getVolume();
            }
        }
        //if profit is negative stop
        if(value - vans[i].getCost() <= 0) break;

        //remove deliveries from the poll
        for(auto d :chosen){
            std::remove(deliveries.begin(), deliveries.end(), d);
        }

        //save combination of van and deliveries
        ret.push_back(Combination(vans[i], chosen, value));

        //progress bar
        std::cout << "Progress: [" << std::string(progress, '#') << std::string(50-progress, '-') << "] " << progress*2 << "%\n";
        progress++;
    }
    std::cout << "Progress: [" << std::string(50, '#') << "] 100%\n";

    //price, reward, profit, number of vans stats
    int value = 0;
    int price = 0;
    for(auto comb : ret){
        value += comb.getValue();
        price += comb.getVan().getCost();
    }
    std::cout << "number of vans " << ret.size() << std::endl;
    std::cout << "total value " << value << std::endl;
    std::cout << "price " << price << std::endl;
    std::cout << "profit " << value-price << std::endl;

    return ret;
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

bool sortByCost(const Van &v1, const Van &v2) {
    return v1.getCost() < v2.getCost();
}

double compose(int x, int y){ //it rounds to 3 decimal cases (ignores whats after)
    double ans = sqrt(pow(x, 2) + pow(y, 2));
    return floor(ans*1000) / 1000;
}

bool compareComposedDelivery(const Delivery &del1, const Delivery &del2){
    return compose(del1.getVolume(), del1.getWeight()) < compose(del2.getVolume(), del2.getWeight());
}

vector<Delivery> firstFitIncreasingCen3(vector<Delivery> &deliveries) {
    unsigned time = 28800;
    bool done = false;
    vector<Delivery> result;
    std::sort(deliveries.begin(), deliveries.end(), compareTime);
    auto delPtr = deliveries.begin();
    while (!done) {
        unsigned thisDuration = delPtr->getDuration();
        if (thisDuration < time && delPtr != deliveries.end()) {
            time -= thisDuration;
            result.push_back(*delPtr);
            delPtr++;
        } else {
            done = true;
        }
    }
    return result;
}

bool compareTime(const Delivery &del1, const Delivery &del2) {
    return (del1.getDuration() < del2.getDuration());
}

bool loadVans(vector<Van> &vans) {
    ifstream file;
    file.open("../../input/carrinhas.txt");
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
    file.open("../../input/encomendas.txt");
    if(!file.is_open()) return false; //file didnt open, perhaps not found

    string throwaway;
    int volume, weight, reward, duration;
    file >> throwaway >> throwaway >> throwaway >> throwaway; //throaway first line;

    while(file >> volume >> weight >> reward >> duration){
        deliveries.push_back(Delivery(volume, weight, reward, duration)); //create delivery object from file and add it to vector
    }
    return true;
}
