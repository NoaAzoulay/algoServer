//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MATRIXSEARCHABLE_H
#define ALGOPROJECT_MATRIXSEARCHABLE_H

#include <list>
#include <vector>
#include "Searchable.h"
#include "Point.h"
#include <complex>

class MatrixSearchable : public Searchable<Point> {
    int row;
    int col;
    State<Point> ***matrix;
public:
    MatrixSearchable(int r, int c) {
        this->row = r;
        this->col = c;

        //create the matrix by the size we got
        this->matrix = new State<Point> **[row];
        for (int i = 0; i < row; ++i) {
            matrix[i] = new State<Point> *[col];
        }
    }

    void setValInMatrix(vector<vector<double >> vec) override;

    list<State<Point> *> getAllPossibleStates(State<Point> *s, char type) override;

    double calculateHValue(State<Point> *cur) override;

    ~MatrixSearchable() {
        for (int j = 0; j < row; j++) {
            for (int i = 0; i < row; ++i) {
                delete matrix[j][i];
            }
            delete matrix[j];
        }
        delete matrix;
    }
};


#endif //ALGOPROJECT_MATRIXSEARCHABLE_H
