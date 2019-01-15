//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_ASTAR_H
#define ALGOPROJECT_ASTAR_H

#include "Searcher.h"

using namespace std;

template<class T>
class AStar : public Searcher<T> {
public:
    vector<State<T> *> search(Searchable<T> *searchable) override;

    int getNumberOfNodesEvaluated() override;

    double getCost() override;
};

#endif //ALGOPROJECT_ASTAR_H
