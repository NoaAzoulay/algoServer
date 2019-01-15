//
// Created by eliana on 1/14/19.
//

#include "MatrixSearchable.h"

void MatrixSearchable::setValInMatrix(vector<vector<double> > vec) {
    int startI = vec.at(vec.size() - 2).at(0);
    int startJ = vec.at(vec.size() - 2).at(1);
    int goalI = vec.at(vec.size() - 1).at(0);
    int goalJ = vec.at(vec.size() - 1).at(1);
    vec.erase(vec.end());
    vec.erase(vec.end());
    int i = 0, j = 0;
    for (vector<double> line: vec) {
        for (double num: line) {
            auto *p = new Point(i, j);
            matrix[i][j] = new State<Point>(num, p);
            if (i == startI && j == startJ) {
                setStart(matrix[i][j]);
            }
            if (i == goalI && j == goalJ) {
                setGoal(matrix[i][j]);
            }
            j++;
        }
        j = 0;
        i++;
    }
    this->current = matrix[0][0];
}

list<State<Point> *> MatrixSearchable::getAllPossibleStates(State<Point> *s, char typeOfSearch) {
    list<State<Point> *> direction;
    int x = s->getState()->getX();
    int y = s->getState()->getY();

    State<Point> *left = nullptr;
    State<Point> *right = nullptr;
    State<Point> *up = nullptr;
    State<Point> *down = nullptr;

    if (y - 1 >= 0 && matrix[x][y - 1]->getCurrCost() >= 0) {
        left = matrix[x][y - 1];
    }
    if (y + 1 <= col - 1 && matrix[x][y + 1]->getCurrCost() >= 0) {
        right = matrix[x][y + 1];
    }
    if (x - 1 >= 0 && matrix[x - 1][y]->getCurrCost() >= 0) {
        up = matrix[x - 1][y];
    }
    if (x + 1 <= row - 1 && matrix[x + 1][y]->getCurrCost() >= 0) {
        down = matrix[x + 1][y];
    }

    if (right != nullptr) {
        direction.push_back(right);
    }
    if (down != nullptr) {
        direction.push_back(down);
    }
    if (left != nullptr) {
        direction.push_back(left);
    }
    if (up != nullptr) {
        direction.push_back(up);
    }
    return direction;
}

double MatrixSearchable::calculateHValue(State<Point> *curr) {
    State<Point> *goal = this->getGoalState();
    int xCurr = curr->getState()->getX();
    int yCurr = curr->getState()->getY();
    int xGoal = goal->getState()->getX();
    int yGoal = goal->getState()->getY();

    double distance = abs(xCurr - xGoal) + abs(yCurr - yGoal);
    double total = distance + curr->getCurrCost() + curr->getCameFrom()->getTotalCost();
    return total;
}