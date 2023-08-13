// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N, E;
//     cin >> N >> E;

//     vector<vector<int>> graph(N + 1);
//     for (int i = 0; i < E; ++i)
//     {
//         int A, B;
//         cin >> A >> B;
//         graph[A].push_back(B);
//         graph[B].push_back(A);
//     }

//     int L;
//     cin >> L;

//     vector<bool> visited(N + 1, false);
//     vector<int> levelShops;

//     queue<int> bfsQueue;
//     bfsQueue.push(0);

//     visited[0] = true;

//     while (!bfsQueue.empty())
//     {
//         int current = bfsQueue.front();
//         bfsQueue.pop();

//         if (L == 0)
//         {
//             levelShops.push_back(current);
//         }

//         if (L > 0)
//         {
//             L--;
//         }

//         for (int neighbor : graph[current])
//         {
//             if (!visited[neighbor])
//             {
//                 visited[neighbor] = true;
//                 bfsQueue.push(neighbor);
//             }
//         }
//     }

//     if (levelShops.empty())
//     {
//         cout << "-1";
//     }

//     else
//     {
//         sort(levelShops.begin(), levelShops.end());
//         for (int shop : levelShops)
//         {
//             cout << shop << " ";
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// vector<int> adj_list[N];
// bool visited[N];
// int level[N];

// vector<int> con_list[N];

// bool dfs(int u, int p = -1)
// {
//     bool cycleExist = false;
//     visited[u] = true;

//     for (int v : adj_list[u])
//     {
//         if (v == p)
//         {
//             continue;
//         }
//         if (visited[v])
//         {
//             return true;
//         }
//         cycleExist = cycleExist || dfs(v, u);
//     }
//     return cycleExist;
// }

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }

//     bool isCycle = false;

//     for (int i = 1; i <= n; i++)
//     {
//         if (visited[i])
//         {
//             continue;
//         }
//         else
//         {
//             isCycle |= dfs(i);
//         }
//     }

//     if (isCycle)
//     {
//         cout << "cycle detected";
//     }
//     else
//     {
//         cout << "cycle not detected";
//     }

//     // __________
//     return 0;
// }

/*
    input:
    5
    5
    1 2
    2 3
    3 5
    5 4
    4 2
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];

void bfs(int s, int d)
{
    vector<int> distance(N, -1);
    distance[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj_list[u])
        {

            if (distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    cout << distance[d] << endl;
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

    int case_N;
    cin >> case_N;

    for (int i = 0; i < case_N; i++)
    {
        int s, d;
        cin >> s >> d;

        bfs(s, d);
    }

    // _____
    return 0;
}