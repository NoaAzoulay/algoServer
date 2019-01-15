//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SEARCHABLE_H
#define ALGOPROJECT_SEARCHABLE_H

#include "State.h"

using namespace std;

template<class T>
class Searchable {
protected:
    State<T> *current;
    State<T> *start;
    State<T> *goal;
public:
    virtual State<T>* getCurrent() {
        return this->current;
    }

    virtual State<T> *getInitialState() {
        return this->start;
    }

    virtual State<T> *getGoalState() {
        return this->goal;
    }

    virtual void setCurrent(State<T> *c) {
        this->current = c;
    }

    virtual void setStart(State<T> *s) {
        this->start = s;
    }

    virtual void setGoal(State<T> *g) {
        this->goal = g;
    }

    virtual void setCurrVisited() {
        this->current->setIsVisited();
    }

    virtual bool getCurrVisited() {
        return current->getIsVisited();
    }

    virtual list<State<T> *> getAllPossibleStates(State<T> *s) = 0;

    virtual double calculateHValue(State<T> *cur) = 0;

    virtual void setValInMatrix(vector<vector<double >> vec) = 0;


};

#endif //ALGOPROJECT_SEARCHABLE_H
