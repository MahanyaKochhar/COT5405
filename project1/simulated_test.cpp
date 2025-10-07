#include "graph_operations.h"
#include "graph_simulator.h"
#include<iostream>
#include<functional>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<function<vector<vector<int>>(int)>> types = {nCycle,complete,empty,heap};
    for(auto& func : types)
    {
        vector<vector<int>>adjlist = func(N);
        
        connectedComponents
        oneCycle
        shortestPaths

    }

}