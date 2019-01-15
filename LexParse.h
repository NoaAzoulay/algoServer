//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_LEXER_H
#define ALGOPROJECT_LEXER_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LexParse {
public:
    virtual vector<vector<double>> splitByLines(string &s, const char &delimiter) = 0;
};

#endif //ALGOPROJECT_LEXER_H
