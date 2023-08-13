#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

vector<int> con_list[N];

void dfs(int u)
{
    visited[u] = true;
    con_list[u].push_back(u);

    for (int v : adj_list[u])
    {
        con_list[u].push_back(v);
        if (visited[v])
        {
            continue;
        }
        dfs(v);
    }
}
//
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << "visiting " << u << endl;
        q.pop();

        for (auto v : adj_list[u])
        {
            if (visited[v] == true)
            {
                continue;
            }

            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
};
//
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

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        dfs(i);
        cc++;
    }

    cout << "Number of CC : " << cc << endl;

    for (int i = 1; i <= cc; i++)
    {
        cout << "Number of child for cc" << i << " is : ";
        for (int x : con_list[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    // _____
    return 0;
}