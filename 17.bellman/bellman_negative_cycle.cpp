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
    vector<edge> vc;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge ed(a, b, w);
        vc.push_back(ed);
    }

    int dis[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

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
        cout << "neg cycle detected";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "dis of " << i << " is " << dis[i] << " " << endl;
        }
    }

    // __________
    return 0;
}

/*
input:
4 4
1 2 5
2 3 2
3 4 -2
1 4 10
*/