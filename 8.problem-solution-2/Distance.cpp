/*
    Problem Statement:
    You will be given an undirected graph as input.
    You will be given a query Q, for each query you will be given a source S and a destination D.
    You need to tell the minimum distance from source to destination for each query.

    Note: If there is no path in between the source and destination, print -1.

    Input Format
    First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
    Next E lines will contain A, B which means there is a edge between node A and B.
    Next line will contain Q, the number of queries.
    For each query every line will contain S and D.
    Constraints

    1 <= N, E <= 1000
    1 <= Q <= 1000
    0 <= S, D <= 10^5

    Output Format
    Output the minimum distance from source to destination for each query.

    Sample Input 0
    6 7
    0 1
    0 2
    1 2
    0 3
    4 2
    3 5
    4 3
    6
    0 5
    1 5
    2 5
    2 3
    1 4
    0 0

    Sample Output 0
    2
    3
    3
    2
    2
    0
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];

bool visited[N];
int dis = 0;

void find_distance(int u, int target)
{
    visited[u] = true;
    if (u == target)
    {
        return;
    }
    else
    {
        dis += 1;
    }

    for (auto v : adj_list[u])
    {
        if (visited[v] == true)
        {
            continue;
        }

        find_distance(v, target);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    find_distance(0, 5);

    cout << dis;

    // for (int i = 0; i < m; i++)
    // {
    //     for (auto v : adj_list[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    // _____
    return 0;
}