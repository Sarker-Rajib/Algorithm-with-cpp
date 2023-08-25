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

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
int dis[N];
bool vis[N];

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (vis[parentNode])
        {
            continue;
        }
        vis[parentNode] = true;
        int parentCost = parent.first;
        for (auto vpair : v[parentNode])
        {
            int childNode = vpair.first;
            int childCost = vpair.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    int s, t;
    cin >> s >> t;
    dijkstra(s);

    for (int i = 1; i <= t; i++)
    {
        int d, l;
        cin >> d >> l;
        if (dis[d] <= l)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    // ______
    return 0;
}