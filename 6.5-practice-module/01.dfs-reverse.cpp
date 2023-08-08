/*Question: You will be given an undirected graph.
Print its DFS traversal in reverse order. Consider root as 1.*/

// sample input:           sample Output: 3 4 2 1
// 4
// 4
// 1 2
// 4 3
// 3 2
// 2 4

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];

bool visited[N];

bool dfs(int u)
{
    visited[u] = true;

    for (int v : adj_list[u])
    {
        if (visited[v] == true)
        {
            continue;
        }

        dfs(v);
    }

    cout << u << " ";
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
    }

    dfs(1);

    // _____
    return 0;
}