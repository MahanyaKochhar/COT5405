#include "graph_operations.h"
#include<queue>
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

void checkCycle(vector<vector<int>>&adjlist,int u,int p,vector<bool>& visited,vector<int>&curr,int& st,vector<int>& ans)
{
    visited[u] = true;
    curr.push_back(u);
    for(auto v : adjlist[u])
    {
        if(!visited[v])
        {
            checkCycle(adjlist,v,u,visited,curr,st,ans);
        }
        else if(visited[v] && v != p && ans.size() == 0)
        {
            ans = curr;
            st = v;
        }
    }
    curr.pop_back();
}

vector<int> oneCycle(vector<vector<int>>& adjlist)
{
    vector<int>fin;
    int N = adjlist.size();
    vector<bool>visited(N,false);
    vector<int>ans;
    vector<int>curr;
    int st = -1;
    for(int i = 0; i < N ; i++)
    {
        if(!visited[i])
        {
            checkCycle(adjlist,i,-1,visited,curr,st,ans);
            if(st != -1)
            {
                break;
            }
        }
    }
    bool start = false;
    for(int i = 0 ; i < ans.size();i++)
    {
        if(ans[i] == st)
        {
            start = true;
        }
        if(start == true)
        {
            fin.push_back(ans[i]);
        }
    }
    if(st != -1)
        fin.push_back(st);
    return fin;
}

map<int,vector<int>> shortestPaths(vector<vector<int>>adjlist,int s)
{
    map<int,vector<int>>res;
    int N = adjlist.size();
    vector<int> d(N,INT_MAX);
    vector<int>p(N,-1);
    priority_queue<pair<int,int>>pq;
    d[s] = 0;
    p[s] = s;
    pq.push({0,s});
    while(!pq.empty())
    {
        pair<int,int> curr = pq.top();
        int dist = -curr.first;
        int u = curr.second;
        pq.pop();
        if(d[s] != dist)
        {
            continue;
        }
        for(auto v : adjlist[u])
        {
            if(d[u] + 1 < d[v])
            {
                d[v] = d[u] + 1;
                p[v] = u;
                pq.push({-d[v],v});
            }
        }
    }

    for(int i = 0 ; i < N ; i++)
    {
        vector<int>path;
        if(p[i] == -1)
        {
            continue;
        }
        while(p[i] != i)
        {
            path.push_back(i);
            i = p[i];
        }
        path.push_back(i);
        res[i] = path;
    }
    return res;
}