//
// Created by eliana on 1/14/19.
//

#include <sys/types.h>
#include <pthread.h>
#include "Main.h"
#include "Point.h"
#include "Searcher.h"
#include "AStar.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "SolverHandler.h"
#include "MyTestClientHandler.h"

pthread_mutex_t mutex;
pthread_mutex_t mutexFile;

int main(int argc, char *argv[]) {
    pthread_mutex_init(&mutex, nullptr);
    pthread_mutex_init(&mutexFile, nullptr);
    Searcher<Point> *searcher1 = new BestFirstSearch<Point>();
    Searcher<Point> *searcher2 = new AStar<Point>();
    Searcher<Point> *searcher3 = new BFS<Point>();
    Searcher<Point> *searcher4 = new DFS<Point>();

    auto *solver = new SolverHandler(searcher1);
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyTestClientHandler(cacheManager, solver);
    server_side::Server *server = new MyParallelServer();
    server->open(atoi(argv[1]), clientHandler);
    while(true);
}
