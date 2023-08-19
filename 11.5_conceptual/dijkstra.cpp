#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long int INF = 1e18;

vector<pair<int, int>> adj[N];
long long int d[N];
bool visited[N];

int nodes, edges;

// dijkstra implemented function
void dijkstra(int s)
{
    // set infinite for all distance
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }

    // set 0 for own distance
    d[s] = 0;

    // create a priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // push source
    pq.push({d[s], s});

    while (!pq.empty())
    {
        // get top element from the queue;
        pair<int, int> f = pq.top();
        pq.pop();

        int selectedNode = f.second;

        if (visited[selectedNode])
        {
            continue;
        }
        visited[selectedNode] = true;

        for (auto child : adj[selectedNode])
        {
            int weight_cost = child.first;
            int v = child.second;

            if (d[selectedNode] + weight_cost < d[v])
            {
                d[v] = d[selectedNode] + weight_cost;
                pq.push({d[v], v});
            }
        }
    }
};

// main function
int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int source = 1;
    dijkstra(source);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "Dis of " << source
             << " to " << i << " "
             << d[i] << endl;
    }

    // _____
    return 0;
}