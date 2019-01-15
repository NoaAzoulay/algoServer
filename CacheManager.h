//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_CHACHMANAGER_H
#define ALGOPROJECT_CHACHMANAGER_H

#include <string>

using namespace std;

class CacheManager {
public:
    virtual bool isExist(string problem) = 0;

    virtual string popSolution(string problem) = 0;

    virtual void addSolution(string problem, string solution) = 0;

    virtual ~CacheManager() = default;
};

#endif //ALGOPROJECT_CHACHMANAGER_H
