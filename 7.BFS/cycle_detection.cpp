#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

vector<int> con_list[N];

bool dfs(int u, int p = -1)
{
    bool cycleExist = false;
    visited[u] = true;

    for (int v : adj_list[u])
    {
        if (v == p)
        {
            continue;
        }
        if (visited[v])
        {
            return true;
        }
        cycleExist = cycleExist | dfs(v, u);
    }
    return cycleExist;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool isCycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        else
        {
            isCycle |= dfs(i);
        }
    }

    if (isCycle)
    {
        cout << "cycle detected";
    }
    else
    {
        cout << "cycle not detected";
    }

    // __________
    return 0;
}

/*
    input:
    5
    5
    1 2
    2 3
    3 5
    5 4
    4 2
*/