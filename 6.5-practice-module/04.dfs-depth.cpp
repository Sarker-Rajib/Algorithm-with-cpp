/*  Question: You will be given an undirected graph as input.
    This graph will contain only one connected component.
    The edge number will be exactly node-1. Then take a node from the input and print its depth.
    Consider root as 1.

    In:               out: Depth of 7 = 1
    7
    6
    1 2
    2 4
    2 5
    1 3
    3 6
    1 7
    7

    in:               Depth of 4 = 2
    7
    6
    1 2
    2 4
    2 5
    1 3
    3 6
    1 7
    4

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

int depth[N];

void dfs(int u)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (visited[v] == true)
        {
            continue;
        }
        depth[v] = depth[u] + 1;

        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    dfs(1);

    int d;
    cin >> d;

    cout << "Depth of " << d << " = " << depth[d];

    // _____
    return 0;
}
