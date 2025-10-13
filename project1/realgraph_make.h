#ifndef REALGRAPH_MAKE_H
#define REALGRAPH_MAKE_H
#include<vector>
std::vector<std::vector<int>> readEdges(int a);

std::vector<std::vector<int>> readRoadEdges(int a);

std::vector<std::vector<int>> constructAdjacencyList(std::vector<std::vector<int>> edges);


#endif