//
// Created by eliana on 1/15/19.
//

#include "LexParse.h"

vector<vector<double>> LexParse::splitByLines(string &s, const char &delimiter) {
    string buff;
    double num = 0;
    vector<vector<double>> matrixVec;
    vector<double> tempVec;

    for (auto c:s) {
        if (c == ' ' || (c == delimiter && buff.empty())) {
            continue;
        }

        // while n != delimiter, add val to buffer
        if (c != delimiter) {
            buff += c;
            continue;
        }

        //if the val is neg, convert it to neg double
        if (buff[0] == '-') {
            buff.erase(0, 1);
            num = 0;
            try {
                num = -1 * stod(buff);
            } catch (exception &e) {
                cout << "error. problem convert to double";
            }
            tempVec.push_back(num);
            buff = "";
            continue;
        }

        //if we finished reading a line
        if (c == '\n') {
            //if the val is neg, convert it to neg double
            if (buff[0] == '-') {
                buff.erase(0, 1);
                num = 0;
                try {
                    num = -1 * stod(buff);
                } catch (exception &e) {
                    cout << "error. problem convert to double";
                }
                tempVec.push_back(num);

                //move to the next vector in the vector<vector<double>> matrixVec
                matrixVec.push_back(tempVec);
                tempVec.clear();
                buff = "";
            } else {
                num = 0;
                try {
                    num = stod(buff);
                } catch (exception &e) {
                    cout << "error. problem convert to double";
                }
                tempVec.push_back(num);

                //move to the next vector in the vector<vector<double>> matrixVec
                matrixVec.push_back(tempVec);
                tempVec.clear();
                buff = "";
                continue;
            }
        }

        num = 0;
        try {
            num = stod(buff);
        } catch (exception &e) {
            cout << "error. problem convert to double";
        }
        tempVec.push_back(num);
        buff = "";
    }
    return matrixVec;
}