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
    vector<string>desc = {"N Cycle Graph", "Complete Graph","Empty Graph","Heap"};
    for(int i = 0 ; i < types.size();i++)
    {
        cout << desc[i] << "\n";
        vector<vector<int>>adjlist = types[i](N);

        vector<vector<int>> connectedComponentsList = connectedComponents(adjlist);
        cout << "Total Number of Components -> " << connectedComponentsList.size() << "\n";
        for(int i = 0 ; i < connectedComponentsList.size(); i++)
        {
            cout << "Component " << i + 1 << "\n";
            for(int j = 0 ; j < connectedComponentsList[i].size();j++)
            {
                cout << connectedComponentsList[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "*********" << "\n";
        vector<int> cycle = oneCycle(adjlist);
        if(cycle.size() != 0)
        {
            cout << "Cycle Exists!" << "\n";
        }
        else
        {
            cout << "No Cycle exists!" << "\n";
        }
        for(int i = 0 ; i < cycle.size();i++)
        {
            cout << cycle[i] << " ";
        }
        cout << "\n";
        cout << "*********" << "\n";
        map<int,vector<int>> paths = shortestPaths(adjlist,0);
        cout << "Shortest Paths with node " << 0 << " as the source." << "\n";
        for(auto pair : paths)
        {
            cout << "Path from " << pair.first << " to " << 0 << "\n";
            for(auto& x : paths[pair.first])
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        cout << "=============" << "\n";
    }

}