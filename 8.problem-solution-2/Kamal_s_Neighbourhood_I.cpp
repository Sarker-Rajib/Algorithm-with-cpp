/*
    Problem Statement:
    Kamal lives in mazenda city.
    In his neighbourhood there are several houses too.
    Some of them are directly connected to Kamal 's house, and some of them are indirectly connected.
    But the roads are two-way as usual.
    If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1.
    Can you tell how many houses are directly connected to Kamal' s house if his house number is K?

    Input Format
    First line will contain N and E,
    the number of houses and roads respectively.
    Next E lines will contain A and B, means there is a road between A house and B house.
    You can go from A to B and also B to A.
    Next line will contain K, the number of Kamal's house Constraints
    0 < N <= 20 0 <= E <= 190 0 <= A,
    B < N 0 <= K < N
    Output Format

    Output the number of houses that are directly connected to Kamal's house.
    Sample Input 0
    6
    5
    0 1
    0 2
    0 3
    2 3
    4 5
    2
    Sample Output 0
    2
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int d_c_house = 0;

void bfs(int s)
{
    for (int v : adj[s])
    {
        d_c_house++;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;
    bfs(k);

    cout << d_c_house << endl;

    // _____
    return 0;
}
