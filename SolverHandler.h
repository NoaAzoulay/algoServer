//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_SOLVERHANDLER_H
#define ALGOPROJECT_SOLVERHANDLER_H

#include "Solver.h"
#include "Searcher.h"
#include "LexParse.h"
#include "MatrixSearchable.h"

class SolverHandler : public Solver {
    Searcher<Point> *searcher;
    LexParse *lexParse;
public:
    SolverHandler(Searcher<Point> *s) {
        this->searcher = s;
    }

    string solve(string problem) override;

    string getDirections(vector<State<Point> *> solution) override;

    bool bigOrSmall(int curr, int next) override;

    ~SolverHandler() override {
        delete searcher;
        delete lexParse;
    }
};

#endif //ALGOPROJECT_SOLVERHANDLER_H
