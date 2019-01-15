//
// Created by eliana on 1/15/19.
//

#ifndef ALGOPROJECT_BFS_H
#define ALGOPROJECT_BFS_H

#include "Searcher.h"

using namespace std;

template<class T>
class BFS : public Searcher<T> {
private:
    int evaluated;
    double cost;
public:

    BFS() {
        this->evaluated = 0;
        this->cost = 0;
    }

    vector<State<T> *> search(Searchable<T> *searchable) {
        list<State<T> *> myList;
        vector<State<T> *> path;

        //put the start state in the front of the list, mark as visited, and increase the evaluated
        myList.push_back(searchable->getInitialState());
        this->evaluated++;
        searchable->setCurrVisited();

        //run until we have no more state to go to
        while (myList.size() > 0) {
            //save the state from the list, and than erase it from the list
            State<T> *parent = myList.front();
            myList.pop_front();

            //check if we got to the goal of the path
            if (parent->equals(searchable->getGoalState())) {
                this->evaluated++;

                //if we are not on the start state of the searchable
                while (parent->getParent() != nullptr) {
                    //go over all the state we got throw
                    path.push_back(parent);
                    this->cost += parent->getCost();
                    parent = parent->getParent();
                }

                this->cost += parent->getCost();
                path.push_back(parent);
                vector<State<T> *> returnBack;

                //insert to new vector in the write direction, and return it to the client
                int i = 0;
                for (i = path.size() - 1; i >= 0; i--) {
                    returnBack.push_back(path.at(i));
                }
                return returnBack;
            }

            list<State<T> *> states = searchable->getAllPossibleStates(parent, 'B');
            //get all the sons of the state we are looking on it now
            for (State<T> *state : states) {
                bool visited = state->getIsVisited();

                //for every state that is not visited it, set his parent, push it to the list, set as current state
                //and increase the evaluate by 1
                if (!visited) {
                    state->setIsVisited();
                    state->setCameFrom(parent);
                    myList.push_back(state);
                    searchable->setCurrent(state);
                    this->evaluated++;
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return this->evaluated;
    }

    double getCost() override {
        return this->cost;
    }
};

#endif //ALGOPROJECT_BFS_H
