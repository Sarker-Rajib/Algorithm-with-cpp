/*Question: You will be given an adjacency matrix for a directed graph (index starting from 1) as input.
Now, convert it to an adjacency list and print it.

in:
3
5
1 2
2 3
1 3
3 1
3 2


out:
0 1 1
0 0 1
1 1 0

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];

int main()
{
    int n, m;
    cin >> n >> m;

    int matrix[n][n] = {0};

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        for (auto v : adj_list[i + 1])
        {
            matrix[i][v - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // _____
    return 0;
}