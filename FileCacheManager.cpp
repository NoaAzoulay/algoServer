//
// Created by eliana on 1/14/19.
//

#include "FileCacheManager.h"

bool FileCacheManager::isExist(string problem) {
    try{
        pthread_mutex_lock(&mutexMap);
        if ( solutions.find(problem) == solutions.end() ) {
            pthread_mutex_unlock(&mutexMap);
            return false;
        } else {
            pthread_mutex_unlock(&mutexMap);
            return true;
        }
    } catch (exception &e){
        pthread_mutex_unlock(&mutexMap);
        return false;
    }
}

string FileCacheManager::popSolution(string problem) {
    string solution;
    try {
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem) = solution;
        pthread_mutex_unlock(&mutexMap);
        return solution;
    } catch (exception &e) {
        pthread_mutex_unlock(&mutexMap);
        return nullptr;
    }
}

void FileCacheManager::addSolution(string problem, string solution) {
    pthread_mutex_lock(&mutexFile);
    solutions.insert(pair<string, string>(problem, solution));
    pthread_mutex_unlock(&mutexFile);
}