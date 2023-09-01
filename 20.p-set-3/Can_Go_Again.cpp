#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int u;
    int v;
    int w;

    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    int maxW = 0;
    vector<edge> vc;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge ed(a, b, w);
        vc.push_back(ed);
        maxW = max(maxW, w);
    }

    long long dis[n + 1];
    const long long INF = 1e18;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;
    dis[s] = 0;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < vc.size(); j++)
        {
            edge edg = vc[j];
            int a = edg.u;
            int b = edg.v;
            int w = edg.w;

            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool cycle = false;

    for (int j = 0; j < vc.size(); j++)
    {
        edge edg = vc[j];
        int a = edg.u;
        int b = edg.v;
        int w = edg.w;

        if (dis[a] + w < dis[b])
        {
            cycle = true;
            break;
            dis[b] = dis[a] + w;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        int t;
        cin >> t;
        while (t--)
        {
            int cn;
            cin >> cn;
            if (dis[cn] > maxW)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[cn] << endl;
            }
        }
    }

    // __________
    return 0;
}
