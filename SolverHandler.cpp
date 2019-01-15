//
// Created by eliana on 1/15/19.
//

#include "SolverHandler.h"

string SolverHandler::solve(string problem) {
    string finalSolution;

    //split all the long problem to values insert in vector<vector<double>>
    vector<vector<double>> vec = this->lexParse->splitByLines(problem, ',');

    //save the first line to get the number of col we will need for the matrix
    vector<double> first = vec.at(0);

    //create the matrix by the specific size we have
    auto *matrix = new MatrixSearchable(vec.size() - 2, first.size());
    matrix->setValInMatrix(vec);

    //put the matrix as a searchable so we can send it to the algorithm
    Searchable<Point> *searchable = matrix;
    vector<State<Point> *> solution = searcher->search(searchable);

    //send to a function that returns the direction of the route that the client must go
    finalSolution = getDirections(solution);

    //delete the matrix and return the path
    delete matrix;
    return finalSolution;
}

string SolverHandler::getDirections(vector<State<Point> *> solution) {
    string final;
    for (int i = 1; i < solution.size(); i++) {
        int prevX = solution.at(i - 1)->getState()->getX();
        int prevY = solution.at(i - 1)->getState()->getY();

        int currX = solution.at(i)->getState()->getX();
        int currY = solution.at(i)->getState()->getY();

        //set the direction
        if (bigOrSmall(prevY, currY)) {
            final += "Right, ";
            continue;
        }
        if (!bigOrSmall(prevY, currY)) {
            final += "Left, ";
            continue;
        }

        if (bigOrSmall(prevX, currX)) {
            final += "Down, ";
            continue;
        }
        if (!bigOrSmall(prevX, currX)) {
            final += "Up, ";
        }
    }

    final.erase(final.length() - 2, 2);
    return final;
}

bool SolverHandler:: bigOrSmall(int prev, int curr){
    return prev < curr;
}