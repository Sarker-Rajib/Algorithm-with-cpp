#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
int mx = 0;

void setA(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
};

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        /* code */
        node = parent[node];
    }
    return node;
};

void dsu_union(int a, int b)
{
    // union by size
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            mx = max(mx, parentSize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx, parentSize[leaderB]);
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    setA(n);

    int cmpo = n;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            cmpo--;
            dsu_union(a, b);
        }
        cout << cmpo << " " << mx << endl;
    }

    // __________
    return 0;
}
