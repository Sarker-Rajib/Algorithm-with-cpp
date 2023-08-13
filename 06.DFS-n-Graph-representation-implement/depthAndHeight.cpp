#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int depth[N];
int height[N];

bool visited[N];

void dfs(int u)
{
    // section 1
    visited[u] = true;
    // cout << " visited Node " << u << endl;

    for (int v : adj[u])
    {
        // section 2
        if (visited[v] == true)
        {
            continue;
        }
        depth[v] = depth[u] + 1;
        dfs(v);
        if (height[v] + 1 > height[u])
        {
            height[u] = height[v] + 1;
        }

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
        adj[v].push_back(u);
    }

    dfs(0);

    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << ": "
             << height[i]
             << endl;
    }

    cout << "*************" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "node "
             << i << ": "
             << height[i]
             << endl;
    }

    // _____
    return 0;
}