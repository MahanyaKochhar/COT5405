#include "graph_simulator.h"
using namespace std;

vector<vector<int>> nCycle(int N)
{
    vector<vector<int>> adjlist(N);
    adjlist[0].push_back(N - 1);
    adjlist[N - 1].push_back(0);
    for(int i = 1 ; i < N ; i++)
    {
        adjlist[i].push_back(i - 1);
        adjlist[i - 1].push_back(i);
    }
    return adjlist;
}

vector<vector<int>> complete(int N)
{
    vector<vector<int>> adjlist(N);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = i + 1 ; j < N ; j++)
        {
            adjlist[i].push_back(j);
            adjlist[j].push_back(i);
        }
    }
    return adjlist;
}

vector<vector<int>> empty(int N)
{
    vector<vector<int>> adjlist(N);
    return adjlist;
}

bool checkValid(int N,int poss,int i)
{
    if(poss >= 0 && poss < N && poss != i)
    {
        return true;
    }
    return false;
}

vector<vector<int>> heap(int N)
{
    vector<vector<int>>adjlist(N);
    for(int i = 0 ; i < N; i++)
    {
        int v1 = (i - 1) / 2;
        int v2 = 2 * i + 1;
        int v3 = 2 * i + 2;
        if(checkValid(N,v1,i))
        {
            adjlist[i].push_back(v1);
        }
        if(checkValid(N,v2,i))
        {
            adjlist[i].push_back(v2);
        }
        if(checkValid(N,v3,i))
        {
            adjlist[i].push_back(v3);
        }
    }
    return adjlist;
}