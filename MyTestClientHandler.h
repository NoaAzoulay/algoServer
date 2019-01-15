//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MYTESTCLIENTHANDLER_H
#define ALGOPROJECT_MYTESTCLIENTHANDLER_H

#include <cstring>
#include <zconf.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ClientHandler.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    CacheManager *cacheManager;
    Solver *solver;
public:
    MyTestClientHandler(CacheManager *cacheManager1, Solver *solver1) {
        this->cacheManager = cacheManager1;
        this->solver = solver1;
    }

    virtual CacheManager* getCacheManager() = 0;

    virtual Solver* getSolver() = 0;

    void handleClient(int sockID) override;

    ~MyTestClientHandler(){
        delete this->cacheManager;
        delete this->solver;
    }
};


#endif //ALGOPROJECT_MYTESTCLIENTHANDLER_H
