/*
    Q: You will be given a directed graph as input.
    Store this graph in an adjacency list.
    Now, convert this adjacency list to an adjacency matrix (index starting from 1) and print it.
    Consider root as 1.

    SAPMLE 1:
    IN:
    4
    0 0 0 1
    1 0 0 1
    1 1 0 0
    0 0 1 0

    OUT:
    List 1 : 4
    List 2 : 1 4
    List 3 : 1 2
    List 4 : 3

    SAPMLE 2:
    in:
    5
    0 0 0 0 0
    1 0 0 1 1
    1 1 0 1 1
    1 1 1 0 0
    0 0 1 0 0

    out:
    List 1 :
    List 2 : 1 4 5
    List 3 : 1 2 4 5
    List 4 : 1 2 3
    List 5 : 3

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];

int main()
{
    int n;
    cin >> n;

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                adj_list[i + 1].push_back(j + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for (auto v : adj_list[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }

    // _____
    return 0;
}