//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_FILECHACHEMANAGER_H
#define ALGOPROJECT_FILECHACHEMANAGER_H

#include "CacheManager.h"
#include <fstream>
#include <iostream>
#include <map>
#include "MyParallelServer.h"

using namespace std;

class FileCacheManager : public CacheManager {
private:
    fstream cacheFile;
    map<string, string> solutions;

public:
    FileCacheManager() {
        //read from file the previous problems and solution and insert them to the solution map
        ifstream cacheF("cacheFile.txt");
        string problem;
        string solution;
        if (cacheF.is_open()) {
            while (getline(cacheF, problem)) {
                getline(cacheF, solution);
                solutions.insert(pair<string, string>(problem, solution));
            }
            cacheFile.close();
        }
    }

    bool isExist(string problem) override;

    string popSolution(string problem) override;

    void addSolution(string problem, string solution) override;

    ~FileCacheManager() {
        ofstream cacheF("cacheFile.txt");
        if (cacheF.is_open()) {
            for (std::map<string, string>::iterator it = solutions.begin(); it != solutions.end(); ++it) {
                cacheF << it.operator*().first;
                cacheF << it.operator*().second + "\n";
                cacheF.flush();
                cacheF.close();
            }
        }
        cacheF.close();
    }
};


#endif //ALGOPROJECT_FILECHACHEMANAGER_H
