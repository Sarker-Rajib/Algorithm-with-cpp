#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
// vector<pair<int, int>> adj[N];

bool visited[N];

void dfs(int u)
{
    // section 1
    visited[u] = true;
    cout << u << endl;

    for (int v : adj[u])
    {
        // section 2
        if (visited[v] == true)
        {
            continue;
        }

        dfs(v);

        // section 3
    }
    // sectioon 4
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
        // adj[v].push_back(u);
    }

    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;

    //     adj[u].push_back({v, w});
    //     adj[v].push_back({u, w});
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "List " << i << ": ";
    //     for (auto j : adj[i])
    //     {
    //         cout << "(" << j.first
    //              << ", " << j.second << ")";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": ";
    //     for (auto j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    dfs(1);

    // _____
    return 0;
}