#include "realgraph_make.h"
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

vector<vector<int>> readEdges(int a)
{
    vector<vector<int>>edges;
    ifstream inputCsv("./twitch_edges.csv");
    string line;
    vector<vector<string>>rows;
    while(getline(inputCsv,line))
    {
        vector<string>row;
        stringstream ss(line);
        string cell;
        while(getline(ss,cell,','))
        {
            row.push_back(cell);
        }
        rows.push_back(row);
    }
    inputCsv.close();

    for(int i = 1 ; i < rows.size();i++)
    {
        int u = stoi(rows[i][0]);
        int v = stoi(rows[i][1]);
        edges.push_back({u,v});
    }
    // cout << edges.size();
   return constructAdjacencyList(edges);

}

vector<vector<int>> readRoadEdges(int a)
{
    vector<vector<int>> edges;
    ifstream file("./road_edges_tx.txt");
    
    
    string line;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        if (line[0] == '#') continue;
        
        stringstream ss(line);
        int u, v;
        
        if (ss >> u >> v) {
            edges.push_back({u, v});
        }
    }
    
    file.close();
    
    cout << edges.size() << "\n";
    return constructAdjacencyList(edges);
}


vector<vector<int>> constructAdjacencyList(vector<vector<int>> edges)
{
    int mini = 1e7, maxi = -1;
    for(int i = 0 ; i < edges.size(); i++)
    {
        mini = min(mini,min(edges[i][0],edges[i][1]));
        maxi = max(maxi,max(edges[i][0],edges[i][1]));
    }
    cout << mini << " " << maxi << "\n";

    int nodes = maxi + 1;
    vector<vector<int>>adjlist(nodes);
    for(int i = 0 ; i < edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    return adjlist;
}