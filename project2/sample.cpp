#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int m , n;
    cin >> m >> n;
    vector<vector<bool>>M(m,vector<bool>(n,0));
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cin >> M[i][j];
        }
    }
}