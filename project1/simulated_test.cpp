#include<iostream>
#include "graph_simulator.h"
using namespace std;

void dfs(int u,vector<vector<int>>& adjlist,vector<bool>& visited,vector<int>& fin)
{
    visited[u] = true;
    fin.push_back(u);
    for(auto v : adjlist[u])
    {
        if(!visited[v])
        {
            dfs(v,adjlist,visited,fin);
        }
    }
}

vector<vector<int>> connectedComponents(vector<vector<int>>adjlist)
{
    int N = adjlist.size();
    vector<bool>visited(N,false);
    vector<vector<int>>ans;
    for(int i = 0; i < N ; i++)
    {
        if(!visited[i])
        {
            vector<int>fin;
            dfs(i,adjlist,visited,fin);
            ans.push_back(fin);
        }
    }
    return ans;
}

void checkCycle(vector<vector<int>>&adjlist,int u,int p,vector<bool>& visited,vector<int>& ans)
{
    visited[u] = true;
    for(auto v : adjlist[u])
    {
        if(!visited[v])
        {
            checkCycle(adjlist,v,u,visited,ans);
        }
        else if(visited[v] && u != p)
        {
            // Cycle exists
        }
    }
}

vector<int> oneCycle(vector<vector<int>>adjlist)
{
    int N = adjlist.size();
    vector<bool>visited(N,false);
    vector<int>ans;
    cout << "Here";
    for(int i = 0; i < N ; i++)
    {
        if(!visited[i])
        {
            vector<int>ans;
            checkCycle(adjlist,i,-1,visited,ans);
        }
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>>adjlist = nCycle(N);
    vector<vector<int>>ans = connectedComponents(adjlist);
    // for(int i = 0 ; i < ans.size();i++)
    // {
    //     for(int j = 0 ; j < ans[i].size();j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}