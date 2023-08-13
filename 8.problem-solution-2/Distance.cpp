/*
    Problem Statement:
    You will be given an undirected graph as input.
    You will be given a query Q, for each query you will be given a source S and a destination D.
    You need to tell the minimum distance from source to destination for each query.

    Note: If there is no path in between the source and destination, print -1.

    Input Format
    First line will contain N, the number of nodes and E, the number of edges.
    The value of nodes will be from 0 to 10^5.
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

int level[N];
bool visited[N];

vector<int> nodes;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        nodes.push_back(u);
        q.pop();

        for (int v : adj_list[u])
        {
            if (visited[v])
            {
                continue;
            }
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
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

    int case_n;
    cin >> case_n;

    for (int i = 0; i < case_n; i++)
    {
        int s, d;
        cin >> s >> d;
        bfs(s);

        bool flag = false;
        for (int v : nodes)
        {
            if (v == d)
            {
                flag = true;
            }
        }

        if (flag == false)
        {
            cout << -1 << endl;
        }
        else
        {

            for (int i = 0; i < N; i++)
            {
                if (i == d)
                {
                    cout << level[d] << endl;
                    break;
                }
            }
        }

        nodes.clear();
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
        }
    }

    // _____
    return 0;
}