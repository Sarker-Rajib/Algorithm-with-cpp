/*
    Problem Statement:
    You will be given an undirected graph as input.
    You need to tell the number nodes in each component in ascending order.
    Note: There will be no component with single node.

    Input Format:
    First line will contain N, the number of nodes and E, the number of edges.
    The value of nodes will be from 0 to 1000.
    Next E lines will contain A, B which means there is a edge between node A and B.

    Constraints:
    1 <= N, E <= 1000

    Output Format:
    Output the number of nodes in each component in ascending order.

    Sample Input 0:
    9 7
    0 1
    1 2
    0 2
    2 3
    4 5
    5 7
    8 9

    Sample Output 0
    2 3 4
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

vector<int> adj[N];
bool visited[N];
int arrs[N];

void bfs(int s, int n)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        arrs[n]++;
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == true)
            {
                continue;
            }
            q.push(v);
            visited[v] = true;
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> nums;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        nums.push_back(u);
    }

    int clevel = 1;

    for (int v : nums)
    {
        if (visited[v])
        {
            continue;
        }
        bfs(v, clevel);
        clevel++;
    }

    list<int> results;

    for (int i = 1; i < clevel; i++)
    {
        results.push_back(arrs[i]);
    }

    results.sort();
    for (auto v : results)
    {
        if (v > 1)
        {
            cout << v << " ";
        }
    }

    return 0;
}