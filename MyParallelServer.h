//
// Created by eliana on 1/14/19.
//

#ifndef ALGOPROJECT_MYPARALLELSERVER_H
#define ALGOPROJECT_MYPARALLELSERVER_H



#include "Server.h"

namespace server_side {
    class MyParallelServer : public Server {
    public:
        void open(int port, server_side::ClientHandler *c);

        void stop();

        bool accept();
    };
}

#endif //ALGOPROJECT_MYPARALLELSERVER_H
