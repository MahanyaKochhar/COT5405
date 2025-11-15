#include<iostream>
#include<vector>
#include "data.h"
using namespace std;


int main()
{
    vector<pair<int,int>>szs = {{10,10},{10,100},{10,1000},{100,1000},{1000,1000}};
    for(int k = 0 ; k < szs.size(); k++)
    {
        pair<int,int>sz = szs[k];
        int m = sz.first, n = sz.second;
        vector<vector<bool>>B = generateMatrix(m,n);
        vector<vector<int>>opt(m,vector<int>(n,0));
        cout << "Matrix Dimensions: " << m << " x " << n << "\n";
        cout << "Matrix :" << "\n";
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "***************" << "\n";
        for(int j = 0 ; j < n; j++)
        {
            if(B[0][j] == 0)
            {
                opt[0][j] = 1;
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            if(B[i][0] == 0)
            {
                opt[i][0] = 1;
            }
        }

        for(int i = 1 ; i < m ; i++)
        {
            for(int j = 1 ; j < n ; j++)
            {
                if(B[i][j] == 0)
                {
                    opt[i][j] = 1 + min(opt[i - 1][j - 1],min(opt[i - 1][j],opt[i][j - 1]));
                }
                else
                {
                    opt[i][j] = 0;
                }
            }
        }
        int ans = 0;
        int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(opt[i][j] > ans)
                {
                    ans = opt[i][j];
                    l2 = i;
                    r2 = j;
                }
            }
        }
        cout << "Dimensions of largest square sub matrix: " << ans << " x " << ans << "\n";
        if(ans != 0)
        {
            l1 = l2;
            r1 = r2;
            while(l1 - 1 >= 0 && r1 - 1 >= 0 && min(opt[l1 - 1][r1 - 1],min(opt[l1 - 1][r1],opt[l1][r1 - 1])) != 0)
            {
                l1--;
                r1--;
            }
            cout << "Largest Square Sub Matrix: " << "\n";
            for(int i = l1 ; i <= l2; i++)
            {
                for(int j = r1 ; j <= r2 ; j++)
                {
                    cout << B[i][j] << " ";
                }
                cout << "\n";
            }
        }
        cout << "*************" << "\n";
    }
}

