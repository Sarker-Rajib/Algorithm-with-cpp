#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentlevel[1000];

void setA(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentlevel[i] = 0;
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
    // union by level
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentlevel[leaderA] > parentlevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentlevel[leaderA] < parentlevel[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentlevel[leaderA]++;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    setA(n);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
        {
            cout << "Cycle Detected between: " << a << " " << b << endl;
        }
        else
        {
            dsu_union(a, b);
        }
    }

    // __________
    return 0;
}

/*
input:
5 5
4 5
1 2
2 5
1 4
2 3
*/