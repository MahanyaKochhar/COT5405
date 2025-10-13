#include "graph_operations.h"
#include "graph_simulator.h"
#include "realgraph_make.h"
#include<iostream>
#include<functional>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << "Here" << "\n";
    vector<vector<int>>adjlist = readRoadEdges(N);
    // int fin = 0;
    // for(int i = 0 ; i < adjlist.size();i++)
    // {
    //     int maxi = 0;
    //     for(int j = 0 ; j < adjlist[i].size();j++)
    //     {
    //         maxi = max(maxi,adjlist[i][j]);
    //     }
    //     fin = max(fin,maxi);
    // }
    // cout << fin << "\n";
    connectedComponents(adjlist);
    // for(int i = 0 ; i < adjlist.size();i++)
    // {
    //     cout << i << "-> ";
    //     for(int j = 0 ; j < adjlist[i].size();j++)
    //     {
    //         cout << adjlist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // connectedComponents(adjlist);
    // cout << connectedComponents(adjlist).size();

    // vector<function<vector<vector<int>>(int)>> types = {nCycle,complete,empty,heap,readEdges};
    // vector<string>desc = {"N Cycle Graph", "Complete Graph","Empty Graph","Heap", "Real Graph"};
    // for(int i = 0 ; i < types.size();i++)
    // {
    //     cout << desc[i] << "\n";
    //     vector<vector<int>>adjlist = types[i](N);

    //     vector<vector<int>> connectedComponentsList = connectedComponents(adjlist);
    //     cout << "Total Number of Components -> " << connectedComponentsList.size() << "\n";
    //     for(int i = 0 ; i < connectedComponentsList.size(); i++)
    //     {
    //         cout << "Component " << i + 1 << "\n";
    //         for(int j = 0 ; j < connectedComponentsList[i].size();j++)
    //         {
    //             cout << connectedComponentsList[i][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "*********" << "\n";
    //     vector<int> cycle = oneCycle(adjlist);
    //     if(cycle.size() != 0)
    //     {
    //         cout << "Cycle Exists!" << "\n";
    //     }
    //     else
    //     {
    //         cout << "No Cycle exists!" << "\n";
    //     }
    //     for(int i = 0 ; i < cycle.size();i++)
    //     {
    //         cout << cycle[i] << " ";
    //     }
    //     cout << "\n";
    //     cout << "*********" << "\n";
    //     // map<int,vector<int>> paths = shortestPaths(adjlist,0);
    //     // cout << "Shortest Paths with node " << 0 << " as the source." << "\n";
    //     // for(auto pair : paths)
    //     // {
    //     //     cout << "Path from " << pair.first << " to " << 0 << "\n";
    //     //     for(auto& x : paths[pair.first])
    //     //     {
    //     //         cout << x << " ";
    //     //     }
    //     //     cout << "\n";
    //     // }
    //     cout << "=============" << "\n";
    // }

}