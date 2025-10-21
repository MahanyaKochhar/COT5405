#include "graph_operations.h"
#include "graph_simulator.h"
#include<iostream>
#include<functional>
#include<chrono>
#include<sys/resource.h>
using namespace std::chrono;
using namespace std;

long getMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

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
        auto membefore = getMemoryUsageKB();
        auto start = high_resolution_clock::now();
        vector<vector<int>> connectedComponentsList = connectedComponents(adjlist);
        auto memafter = getMemoryUsageKB();
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Connected Components Duration " << duration.count() << " ns" <<  "\n";
        cout << "Connected Components Memory Peak " << (memafter - membefore) << " KB" << "\n";
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
        membefore = getMemoryUsageKB();
        start = high_resolution_clock::now();
        vector<int> cycle = oneCycle(adjlist);
        memafter = getMemoryUsageKB();
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        cout << "Cycle Detection Duration " << duration.count() << " ns" <<  "\n";
        cout << "Cycle Detection Memory Peak " << (memafter - membefore) << " KB" << "\n";
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
        membefore = getMemoryUsageKB();
        start = high_resolution_clock::now();
        map<int,vector<int>> paths = shortestPaths(adjlist,0);
        memafter = getMemoryUsageKB();
        end = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(end - start);
        cout << "Shortest Paths Duration " << duration.count() << " ns" <<  "\n";
        cout << "Shortest Paths Memory Peak " << (memafter - membefore) << " KB" << "\n";
        cout << "Shortest Paths with node " << 0 << " as the source." << "\n";
        for(auto pair : paths)
        {
            cout << "Path from " << pair.first << " to " << 0 << "\n";
            for(auto& x : paths[pair.first])
            {
                cout << "->";
                cout << x;
            }
            cout << "\n";
        }
        cout << "=============" << "\n";
    }

}