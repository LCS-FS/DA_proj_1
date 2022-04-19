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

    int value = 0;
    for(auto comb : ret){
        value += comb.getValue();
    }
    std::cout << "number of vans " << ret.size();
    std::cout << "number of items " << value;
    return ret;
}
//==================================================================================================================================


vector<Combination> cenario2(vector<Van> vans, vector<Delivery> deliveries) {
    vector<Combination> ret;
    vector<Van> auxV;
    vector<Delivery> auxD;
    int progress = 1;
    std::cout << "It Starts slow but gets faster as it goes on.\n";
    std::cout << "Progress: [" << std::string(50, '-') << "] " << "0%\n";
    //fake best for comparison
    Van fakeVan(-1,-1,-1);
    vector<Delivery> fakeDel = {Delivery(-1, -1, -1, -1)};
    int fakeVal = -1;
    Combination fakeComb(fakeVan, fakeDel, fakeVal);

    for(int i = 0; i < vans.size(); i++){

        //best combination with considering all vans and deliveries that havent been used so far
        Combination best = multiple_bi_01_knapsack_values(vans, deliveries);
        if(best == fakeComb) break; //all remaining combinations have negative profit

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

Combination multiple_bi_01_knapsack_values(vector<Van> &vans, vector<Delivery> &deliveries){
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

    std::sort(regardless.begin(), regardless.end(), sortByProfit); //sort by total value (or number of deliveries if value == 1)

    //make a fake combination to return in case of end
    Van fakeVan(-1,-1,-1);
    vector<Delivery> fakeDel = {Delivery(-1, -1, -1, -1)};
    int fakeVal = -1;


    //if profit is negative, we reached the end and all other combinations that we add are a detriment to the overall profit
    if(regardless[regardless.size()-1].getValue() <= regardless[regardless.size()-1].getVan().getCost()) return Combination(fakeVan, fakeDel, fakeVal);

    return regardless[regardless.size()-1]; //return combination with highest value
}

bool sortByProfit(const Combination &c1, const Combination &c2){
    int profit1 = c1.getValue() - c1.getVan().getCost();
    int profit2 = c2.getValue() - c2.getVan().getCost();
    return profit1 < profit2;
}

double compose(int x, int y) { //it rounds to 3 decimal cases (ignores whats after)
    double ans = sqrt(pow(x, 2) + pow(y, 2));
    return floor(ans*1000) / 1000;
}

bool compareComposedDelivery(const Delivery &del1, const Delivery &del2) {
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
    file.open("../../src/carrinhas.txt");
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
    file.open("../../src/carrinhas.txt");
    if(!file.is_open()) return false; //file didnt open, perhaps not found

    string throwaway;
    int volume, weight, reward, duration;
    file >> throwaway >> throwaway >> throwaway >> throwaway; //throaway first line;

    while(file >> volume >> weight >> reward >> duration){
        deliveries.push_back(Delivery(volume, weight, reward, duration)); //create delivery object from file and add it to vector
    }
    return true;
}


