#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 1e5 + 5;

vector<pi> v[N];
bool vis[N];

int n, e;

class Edge
{
public:
    int a;
    int b;
    int w;

    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void primsAlgo(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(s, s, 0));

    int count = 0;

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();

        int a = parent.a;
        int b = parent.b;
        int w = parent.w;

        if (vis[b])
        {
            continue;
        }

        vis[b] = true;
        edgeList.push_back(parent);

        count++;

        for (auto child : v[b])
        {
            int node = child.first;
            int cost = child.second;

            if (!vis[node])
            {
                pq.push(Edge(b, node, cost));
            }
        }
    }

    long long mincost = 0;
    for (auto val : edgeList)
    {
        mincost += val.w;
    }

    if (count == n)
    {
        cout << mincost;
    }
    else
    {
        cout << -1;
    }
};

int main()
{
    cin >> n >> e;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }

    primsAlgo(1);

    // _____
    return 0;
}