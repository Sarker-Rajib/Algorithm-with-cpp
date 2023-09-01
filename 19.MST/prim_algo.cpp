#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 1e5 + 5;

vector<pi> v[N];
bool vis[N];

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

        // edgeList.erase(edgeList.begin());

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

    for (Edge val : edgeList)
    {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
};

int main()
{
    int n, e;
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