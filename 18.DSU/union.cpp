#include <bits/stdc++.h>
using namespace std;

int parent[1000];

void setA(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
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
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        parent[leaderB] = leaderB;
    }
};

int main()
{
    // setA(7);
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    // __________
    return 0;
}