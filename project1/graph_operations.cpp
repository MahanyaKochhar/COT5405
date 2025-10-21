#include "graph_operations.h"
#include<queue>
#include<iostream>
using namespace std;


vector<int> bfs(int u,vector<vector<int>>&adjlist,vector<bool>&visited)
{
    vector<int> cc;
    cc.push_back(u);
    visited[u] = true;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto& v : adjlist[front])
        {
            if(!visited[v])
            {
                visited[v] = true;
                cc.push_back(v);
                q.push(v);
            }
        }
    }
    return cc;
}


vector<int> dfs(int u,vector<vector<int>>&adjlist,vector<bool>&visited,vector<int>&parent,int& nd1,int& nd2)
{
    vector<int> cc;
    parent[u] = -1;
    stack<int>s;
    s.push(u);
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        if(visited[curr])
        {
            continue;
        }
        visited[curr] = true; 
        cc.push_back(curr);
        for(auto& v : adjlist[curr])
        {
            if(!visited[v])
            {
                parent[v] = curr;
                s.push(v);
            }
            else if(visited[v] && v != parent[curr])
            {
                nd1 = curr;
                nd2 = v;
            }
        }
    }
    return cc;
}

vector<vector<int>> connectedComponents(vector<vector<int>>& adjlist)
{
    int N = adjlist.size();
    vector<bool>visited(N,false);
    vector<int>parent(N,-1);
    vector<vector<int>>ans;
    int nd1 = -1,nd2 = -1;
    for(int i = 0; i < N ; i++)
    {
        if(!visited[i])
        {
            vector<int> cc = dfs(i,adjlist,visited,parent,nd1,nd2);
            ans.push_back(cc);
        }
    }
    return ans;
}


vector<int> oneCycle(vector<vector<int>>& adjlist)
{
    int N = adjlist.size();
    vector<bool>visited(N,false);
    vector<int>parent(N,-1);
    int nd1 = -1,nd2 = -1;
    bool cyclePresent = false;
    for(int i = 0; i < N ; i++)
    {
        if(!visited[i])
        {
            dfs(i,adjlist,visited,parent,nd1,nd2);
            if(nd1 != -1 && nd2 != -1)
            {
                cyclePresent = true;
                break;
            }
        }
    }
    vector<int>cycle;
    if(cyclePresent)
    {
        int tmp = nd1;
        while(nd1 != nd2)
        {
            cycle.push_back(nd1);
            nd1 = parent[nd1];
        }
        cycle.push_back(nd2);
        cycle.push_back(tmp);
    }
    return cycle;
}

map<int,vector<int>> shortestPaths(vector<vector<int>>&adjlist,int s)
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
        if(d[u] != dist)
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
        int node = i;
        vector<int>path;
        if(p[node] == -1)
        {
            continue;
        }
        while(p[node] != node)
        {
            path.push_back(node);
            node = p[node];
        }
        path.push_back(node);
        res[i] = path;
    }
    return res;
}