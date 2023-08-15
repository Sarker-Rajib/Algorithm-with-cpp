#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 10;
// define pair tyoe
typedef pair<int, int> pii;
// declare vector of a pair
vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int sourse)
{
    priority_queue<pii, vector<pii>, greater<pii>> pQ;
    dist[sourse] = 0;
    pQ.push({dist[sourse], sourse});

    while (!pQ.empty())
    {
        int u = pQ.top().second;
        pQ.pop();

        visited[u] = true;

        for (pii vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
            {
                continue;
            }

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pQ.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "D of Node "
             << i
             << " : "
             << dist[i]
             << endl;
    }

    // __________
    return 0;
}