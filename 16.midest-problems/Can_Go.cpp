/*
Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph.
For each edge you will be given A, B and W
which means there is a connection from A to B for which you need to give W cost.
The value of nodes could be from 1 to N.

You will be given a source node S.
Then you will be given a test case T,
for each test case you will be given a destination node D and a cost DW.
You need to tell if you can go to the destination from source using DW cost.

Input Format
First line will contain N and E.
Next E lines will contain A and B.
Next line will contain source node S.
Next line will contain T, the number of test cases.
For each test case, you will get D and DW.
Constraints

1 <= N <= 1000
1 <= E <= N*(N-1)
1 <= S <= N
1 <= T <= 1000
1 <= D <= N
0 <= DW <= 10^9
Output Format

Ouput "YES" or "NO" for each test case if it is possible to go from S to D in DW cost.
Sample Input 0

5 7
1 2 10
1 3 2
3 2 1
2 4 7
3 4 2
4 5 5
2 5 2
1
5
1 0
2 5
3 1
4 4
5 6
Sample Output 0

YES
YES
NO
YES
YES
*/

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<pair<int, int>> v[N];
// int dis[N];
// bool vis[N];

// void dijkstra(int s)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     pq.push({0, s});
//     dis[s] = 0;
//     while (!pq.empty())
//     {
//         pair<int, int> parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         if (vis[parentNode])
//         {
//             continue;
//         }
//         vis[parentNode] = true;
//         int parentCost = parent.first;
//         for (auto vpair : v[parentNode])
//         {
//             int childNode = vpair.first;
//             int childCost = vpair.second;
//             if (parentCost + childCost < dis[childNode])
//             {
//                 dis[childNode] = parentCost + childCost;
//                 pq.push({dis[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     for (int i = 0; i < e; i++)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         v[a].push_back({b, w});
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }

//     int s, t;
//     cin >> s >> t;
//     dijkstra(s);

//     for (int i = 1; i <= t; i++)
//     {
//         int d, l;
//         cin >> d >> l;
//         if (dis[d] <= l)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     // ______
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pair<pii, int>> list_of_edges;
int d[N];
int n, m;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    d[s] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto edge : list_of_edges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
};

int main()
{
    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_of_edges.push_back({{u, v}, w});
    }

    int s, t;
    cin >> s >> t;
    bellman_ford(s);

    for (int i = 1; i <= t; i++)
    {
        int dis, l;
        cin >> dis >> l;
        if (d[dis] <= l)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    // __________
    return 0;
}