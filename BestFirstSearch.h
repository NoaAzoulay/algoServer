//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_BESTFIRSTSEARCH_H
#define ALGOPROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<class T>
class BestFirstSearch : public Searcher<T> {
private:
    int evaluated;
    double pathCost;

    class Comperator {
    public:
        bool operator()(State<T> *left, State<T> *right) {
            return (left->getTotalCost()) > (right->getTotalCost());
        }
    };

public:
    BestFirstSearch() {
        evaluated = 0;
        pathCost = 0;
    }

    bool isExist(priority_queue<State<T> *, vector<State<T> *>, Comperator> open, State<T> *state) {
        while (!open.empty()) {
            if (state->equals(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }

    priority_queue<State<T> *, vector<State<T> *>, Comperator>
    QueueUpdate(priority_queue<State<T> *, vector<State<T> *>, Comperator> &queueOpen) {
        priority_queue<State<T> *, vector<State<T> *>, Comperator> tempVec;
        while (!queueOpen.empty()) {
            State<T> *node = queueOpen.top();
            tempVec.push(node);
            queueOpen.pop();
        }
        return tempVec;
    }

    vector<State<T> *> search(Searchable<T> *searchable) override {
        priority_queue<State<T> *, vector<State<T> *>, Comperator> openList;
        openList.push(searchable->getInitialState());
        unordered_set<State<T> *> closed;
        vector<State<T> *> path;
        while (!openList.empty()) {
            evaluated++;
            State<T> *n = openList.top();
            openList.pop();
            closed.insert(n);


            if (n->equals(searchable->getGoalState())) {
                path.push_back(n);
                while (!n->equals(searchable->getInitialState())) {
                    path.push_back(n->getCameFrom());
                    pathCost += n->getCurrCost();
                    n = n->getCameFrom();
                }
                pathCost += n->getCurrCost();
                vector<State<T> *> vector1;
                for (long i = path.size() - 1; i >= 0; i--) {
                    vector1.push_back(path.at(i));
                }
                return vector1;
            }
            list<State<T> *> neighbors;
            try {
                neighbors = searchable->getAllPossibleStates(n);
            } catch (exception &e) {

            }
            for (State<T> *neighbor : neighbors) { ;
                bool exist = isExist(openList, neighbor);
                if (!exist && closed.count(neighbor) != 1) {
                    neighbor->setCameFrom(n);
                    neighbor->setTotalCost(n->getTotalCost() + neighbor->getCurrCost());
                    openList.push(neighbor);
                } else if (neighbor->getTotalCost() > n->getTotalCost() + neighbor->getCurrCost()) {
                    bool inOpen = isExist(openList, neighbor);
                    neighbor->setTotalCost(n->getTotalCost() + neighbor->getCurrCost());
                    neighbor->setCameFrom(n);
                    openList = QueueUpdate(openList);
                    
                }
            }
        }
        return path;
    }

    int getNumberOfNodesEvaluated() override {
        return evaluated;
    }

    double getPathCost() override {
        return pathCost;
    }


};

#endif //ALGOPROJECT_BESTFIRSTSEARCH_H
