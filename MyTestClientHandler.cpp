//
// Created by eliana on 1/14/19.
//

#include "MyTestClientHandler.h"

CacheManager *MyTestClientHandler::getCacheManager() {
    return this->cacheManager;
}

Solver *MyTestClientHandler::getSolver() {
    return this->solver;
}

void MyTestClientHandler::handleClient(int sockID) {
    char problem[1024] = "";
    char forClient[1024] = "";
    string solution;
    long n;

    //read data from client
    bzero(problem, 1024);
    n = read(sockID, problem, 1023);
    if (n < 0) {
        perror("error. problem reading from socket");
        exit(1);
    }

    //read from client until we get to "end"
    while (strcmp(problem, "end") != 0) {
        strcat(problem, "\n");

        //to the next line from client
        bzero(problem, 1024);
        n = read(sockID, problem, 1023);
        if (n < 0) {
            perror("error. problem reading from socket");
            exit(1);
        }
    }

    //check if we have already solution for the client problem
    if (cacheManager->isExist(problem)) {
        //save the solution in string to send it to the client
        solution = cacheManager->popSolution(problem);
    } else {
        //if we did not find the solution in the map, we will solve it and insert to the map
        solution = solver->solve(problem);
        cacheManager->addSolution(problem, solution);
    }

    //send the solution to the client
    strcpy(forClient, solution.data());
    if (write(sockID, forClient, 1023) < 0) {
        perror("error. problem writing to socket");
        exit(1);
    }

    cout << solution << endl;

    //close the client socket
    close(sockID);
}
