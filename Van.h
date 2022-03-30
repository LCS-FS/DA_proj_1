#ifndef PROJ1_VAN_H
#define PROJ1_VAN_H


class Van {
private:
    int volume, weight, cost;
public:
    int getVolume() const;
    void setVolume(int volume);
    int getWeight() const;
    void setWeight(int weight);
    int getCost() const;
    void setCost(int cost);
};


#endif //PROJ1_VAN_H
