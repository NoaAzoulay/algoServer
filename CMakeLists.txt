cmake_minimum_required(VERSION 3.13)
project(algoProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(algoProject Main.cpp Main.h CacheManager.h ClientHandler.h FileCacheManager.cpp FileCacheManager.h LexParse.h SolverHandler.h MyParallelServer.cpp MyParallelServer.h Server.h MatrixSearchable.cpp MatrixSearchable.h Point.h MyTestClientHandler.cpp MyTestClientHandler.h Searchable.h Searcher.h Solver.h State.h SolverHandler.cpp LexParse.cpp BFS.h DFS.h AStar.h BestFirstSearch.h)