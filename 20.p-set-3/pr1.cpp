#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentLevel[N];

void parentInitialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
};

int dsuFind(int cNode)
{
    while (parent[cNode] != -1)
    {
        cNode = parent[cNode];
    }

    return cNode;
};

void dsuUnion(int leaderA, int leaderB)
{
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderA] < parentLevel[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    parentInitialize(n);

    int cycle = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsuFind(a);
        int leaderB = dsuFind(b);

        if (leaderA == leaderB)
        {
            cycle++;
        }
        else
        {
            dsuUnion(leaderA, leaderB);
        }
    }

    cout << cycle;

    // ____
    return 0;
}