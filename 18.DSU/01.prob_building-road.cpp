
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int parentlevel[N];

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
        dsu_union(a, b);
    }
    map<int, bool> mp;

    for (int i = 1; i <= n; i++)
    {
        int ldr = dsu_find(i);
        mp[ldr] = true;
    }

    vector<int> v;

    for (auto m : mp)
    {
        v.push_back(m.first);
    }

    cout << v.size() - 1 << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    // __________
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// int parent[N];
// int parentSize[N];

// void setA(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentSize[i] = 1;
//     }
// };

// int dsu_find(int node)
// {
//     while (parent[node] != -1)
//     {
//         /* code */
//         node = parent[node];
//     }
//     return node;
// };

// void dsu_union(int a, int b)
// {
//     // union by size
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentSize[leaderA] > parentSize[leaderB])
//         {
//             parent[leaderB] = leaderA;
//             parentSize[leaderA] += parentSize[leaderB];
//         }
//         else
//         {
//             parent[leaderA] = leaderB;
//             parentSize[leaderB] += parentSize[leaderA];
//         }
//     }
// };

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     setA(n);

//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         dsu_union(a, b);
//     }

//     map<int, bool> mp;

//     for (int i = 1; i <= n; i++)
//     {
//         int ldr = dsu_find(i);
//         mp[ldr] = true;
//     }

//     vector<int> v;

//     for (auto m : mp)
//     {
//         v.push_back(m.first);
//         // cout << m.first << " " << m.second << endl;
//     }

//     cout << v.size() - 1 << endl;
//     for (auto i : v)
//     {
//         cout << i << " ";
//     }
//     // __________
//     return 0;
// }
