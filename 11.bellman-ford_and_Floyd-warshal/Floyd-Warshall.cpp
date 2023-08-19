#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int d[N][N];
int n, m;

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "X"
                     << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
};

void dist_intialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
        }
    }
};

void Floyd_Warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    dist_intialize();

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // cout << u << v << w << endl;

        d[u][v] = w;
        d[v][u] = w;
    }

    // print_matrix();

    Floyd_Warshall();

    cout << endl;

    print_matrix();

    // __________
    return 0;
}

/*
7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9

will look like:
0 2 6 X X
2 0 1 6 3
6 1 0 4 X
X 6 4 0 9
X 3 X 9 0

*/

/*
output
0 2 3 7 5
2 0 1 5 3
3 1 0 4 4
7 5 4 0 8
5 3 4 8 0

undirected o
0 2 3 7 5
X 0 1 5 3
X 10 0 4 13
X 6 7 0 9
X 15 16 9 0

*/