#include "data.h"
#include <random>
using namespace std;

vector<vector<bool>> generateMatrix(int M , int N)
{
    vector<vector<bool>>mat(M,vector<bool>(N,0));
    std::random_device rd;                  
    std::mt19937 gen(rd());                 
    std::uniform_int_distribution<> dist(0, 1);
    for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            int coin = dist(gen);
            mat[i][j] = (int)coin;
        }
    }
    return mat;
}