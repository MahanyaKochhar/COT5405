#include<iostream>
#include<vector>
#include <random>
#include "frequency_letters.h"
using namespace std;

void largestWeightCommonSubstring(string a,string b,map<char,double> frequencyMap,double delta,bool fixed)
{
    int m = a.length(), n = b.length();
    vector<vector<double>>opt(m + 1,vector<double>(n + 1,0));
    double ans = 0,l1 = -1,r1 = -1;
    for(int i = 1; i <= m ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                opt[i][j] = opt[i - 1][j - 1] + (fixed ? 1 : frequencyMap[a[i - 1]]);
                if(ans < opt[i][j])
                {
                    ans = opt[i][j];
                    l1 = i;
                    r1 = j;
                }
            }
            else
            {
                opt[i][j] = max(opt[i - 1][j - 1] - delta,0.0);
                if(ans < opt[i][j])
                {
                    ans = opt[i][j];
                    l1 = i;
                    r1 = j;
                }
            }
        }
    }
    cout << "Score of Best(largest score) common substring: " << ans << "\n";
    string res = "";
    while(ans != 0 && l1 > 0)
    {
        if(a[l1 - 1] == b[r1 - 1])
        {
            ans -= (fixed ? 1 : frequencyMap[a[l1 - 1]]);
        }
        else
        {
            ans += delta;
        }
        res.push_back(a[l1 -1]);
        l1--;
        r1--;
    }
    reverse(res.begin(),res.end());
    cout << "Best(largest score) common substring: " << res << "\n";
}


int main()
{
    string a,b;
    cin >> a >> b;

    map<char,double> frequencyMap = readLetterFrequency();

    double minF = 26,maxF = -1;
    for(auto it : frequencyMap)
    {
        minF = min(minF,it.second);
        maxF = max(maxF,it.second);
    }
    cout << "Given w_l is " << 1 << " and delta is " << 10 << " \n";
    largestWeightCommonSubstring(a,b,frequencyMap,10,true);
    cout << "\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(minF, maxF);
    for(int i = 0 ; i < 10 ; i++)
    {
        double delta = dist(gen);
        cout << "Given w_l is frequency of letter in English alphabet "<< "and delta is " << delta << " \n";
        largestWeightCommonSubstring(a,b,frequencyMap,delta,false);
        cout << "\n";
    }

}