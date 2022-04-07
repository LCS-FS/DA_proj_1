#ifndef PROJ1_DELIVERY_H
#define PROJ1_DELIVERY_H


class Delivery {
private:
    int volume, weight, reward, duration;
public:
    Delivery(int volume, int weight, int reward, int duration);
    int getVolume() const;
    void setVolume(int volume);
    int getWeight() const;
    void setWeight(int weight);
    int getReward() const;
    void setReward(int reward);
    int getDuration() const;
    void setDuration(int duration);
};


#endif //PROJ1_DELIVERY_H
