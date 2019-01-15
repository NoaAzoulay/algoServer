//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_STATE_H
#define ALGOPROJECT_STATE_H

#include <list>

using namespace std;

template<class T>
class State {
    T *state;
    State<T> *cameFrom;
    double currCost;
    double totalCost;
    bool isVisited = false;
    double heuristicCost;
public:
    State(double cost, T *state) {
        this->currCost = cost;
        this->totalCost = cost;
        this->cameFrom = nullptr;
        this->state = state;
        this->heuristicCost = 0;
    }

    T *getState() {
        return this->state;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    double getCurrCost() {
        return this->currCost;
    }

    double getTotalCost() {
        return this->totalCost;
    }

    bool getIsVisited() {
        return this->isVisited;
    }

    double getHeuristicCost() {
        return this->heuristicCost;
    }

    void setCameFrom(State<T> *parent) {
        this->cameFrom = parent;
    }

    void setCurrCost(double x) {
        this->currCost = x;
    }

    void setTotalCost(double d) {
        this->totalCost += d;
    }

    void setIsVisited() {
        this->isVisited = true;
    }

    void setHeuristicCost(double h) {
        this->heuristicCost = h;
    }

    bool equals(State<T> *s) {
        return this->state == s;
    }

    void initializeTotalCost() {
        this->totalCost = currCost;
    }

    ~State() {
        delete this->state;
    }
};

#endif //ALGOPROJECT_STATE_H
