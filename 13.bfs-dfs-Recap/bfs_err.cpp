
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dis[N];
bool vis[N];
vector<int> adj[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent])
        {
            if (!vis[child])
            {
                q.push(child);
                dis[child] = dis[parent] + 1;
                vis[child] = true;
            }
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src = 1;
    bfs(src);

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " :: " << dis[i] << endl;
    }

    // __________
    return 0;
}
