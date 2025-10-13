#ifndef GRAPH_OPERATIONS_H
#define GRAPH_OPERATIONS_H
#include<vector>
#include<map>

std::vector<std::vector<int>> connectedComponents(std::vector<std::vector<int>>& adjlist);

std::vector<int> oneCycle(std::vector<std::vector<int>>& adjlist);

std::map<int,std::vector<int>> shortestPaths(std::vector<std::vector<int>> &adjlist,int s);

#endif