//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_HANDLECLIENT_H
#define ALGOPROJECT_HANDLECLIENT_H

#include "Solver.h"
#include <iostream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int sockID) = 0;

    virtual ~ClientHandler() = default;
};

#endif //ALGOPROJECT_HANDLECLIENT_H
