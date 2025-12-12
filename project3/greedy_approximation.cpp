#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cout << "Enter no of elements in the universe" << "\n";
    cin >> N;
    cout << "Enter no of subsets " << "\n";
    cin >> M;
    cin.ignore();
    vector<vector<int>> subsets;
    for (int i = 1; i <= M; i++)
    {
        cout << "Enter elements of subset " << i << " separated by spaces: ";
        string line;
        getline(cin, line);

        stringstream ss(line);
        int num;
        vector<int> subset;

        while (ss >> num)
        {
            subset.push_back(num);
        }

        subsets.push_back(subset);
    }

    // Greedy Algorithm
    set<int> cover;
    int pickedSubset = -1;
    bool pickSubset = true;
    vector<int> selected;
    while (cover.size() != N && pickSubset)
    {
        int maxUncovered = 0;
        pickedSubset = -1;
        for (int i = 0; i < subsets.size(); i++)
        {
            int uncovered = 0;
            for (int j = 0; j < subsets[i].size(); j++)
            {
                if (cover.find(subsets[i][j]) == cover.end())
                {
                    uncovered++;
                }
            }
            if (uncovered > maxUncovered)
            {
                pickedSubset = i;
                maxUncovered = uncovered;
            }
        }
        if (pickedSubset != -1)
        {
            selected.push_back(pickedSubset);
            for (int j = 0; j < subsets[pickedSubset].size(); j++)
            {
                cover.insert(subsets[pickedSubset][j]);
            }
        }
        else
        {
            pickSubset = false;
        }
    }

    if (cover.size() == N)
    {
        cout << "Found a cover for the elements." << "\n";
        cout << "No of subsets " << selected.size() << "\n";
        cout << "Picked Subsets : " << "\n";
        for (int i = 0; i < selected.size(); i++)
        {
            for (int j = 0; j < subsets[selected[i]].size(); j++)
            {
                cout << subsets[selected[i]][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No cover exists with the given sets." << "\n";
    }
}