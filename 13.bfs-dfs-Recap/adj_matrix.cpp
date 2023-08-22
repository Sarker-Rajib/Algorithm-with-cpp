#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // __________
    return 0;
}

/**
4 4
1 2
1 3
3 4
4 1
*/