//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SEARCHER_H
#define ALGOPROJECT_SEARCHER_H

#include <vector>
#include "Searchable.h"

template<class T>
class Searcher {
public:
    virtual vector<State<T> *> search(Searchable<T> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;

    virtual double getCost() = 0;
};

#endif //ALGOPROJECT_SEARCHER_H
