//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_DFS_H
#define ALGOPROJECT_DFS_H

#include "Searcher.h"
#include "Searchable.h"
#include <queue>
#include "State.h"
#include "SolverHandler.h"


template <class T>
class DFS : public Searcher<T> {
private:
    int evaluated;
    double pathCost;

public:
    DFS(){
        evaluated =0;
    }
    //the matrix is our "searchable" in this case
    vector<State<T>*> search(Searchable<T>* searchable) override {
        searchable->setCurrVisited();
        //save the path(the solution) and return it in the end
        vector<State<T>*> path;
        this->DFS_alg(searchable, searchable->getInitialState(), path);
        return path;
    }
//the DFS algorithm- getting the matrix, the start point and a vector to update with the path details
    int DFS_alg(Searchable<T>* searchable, State<T>* curr, vector<State<T>*> &path) {
        if(curr->equals(searchable->getGoalState())){
            evaluated++;
            while (curr->getCameFrom() != nullptr) {
                path.push_back(curr);
                pathCost += curr->getCurrCost();
                curr = curr->getCameFrom();
            }
            pathCost += curr->getCurrCost();
            path.push_back(curr);
            vector<State<T>*> vec1;
            for (long i = path.size() - 1; i >= 0 ; i--) {
               vec1.push_back(path.at(i));
            }
            path = vec1;
            return 1;
        }
        curr->setIsVisited();
        evaluated++;
        searchable->setCurrent(curr);
        list<State<T>*> states = searchable->getAllPossibleStates(curr);
        for (State<T>* state : states) {
            bool visited = state->getIsVisited();
            if (!visited) {
                state->setCameFrom(curr);
                if (DFS_alg(searchable, state, path) == 1) {
                    return 1;
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() {
        return pathCost;
    }

};

#endif //ALGOPROJECT_DFS_H
