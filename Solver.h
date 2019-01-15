//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SOLVER_H
#define ALGOPROJECT_SOLVER_H

#include <string>
#include <vector>
#include "State.h"
#include "Point.h"

using namespace std;

class Solver {
public:
    virtual string solve(string problem) = 0;

    virtual string getDirections(vector<State<Point> *> solution) = 0;

    virtual bool bigOrSmall(int curr, int next) = 0;

    virtual ~Solver() = default;
};

#endif //ALGOPROJECT_SOLVER_H
