#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
vector<pii> direc = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1}};
bool is_valid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();
        for (pii d : direc)
        {
            int vi = ui + d.first;
            int vj = uj + d.second;
            if (is_valid(vi, vj) && !visited[vi][vj])
            {
                q.push({vi, vj});
                visited[vi][vj] = true;
                level[vi][vj] = level[ui][uj] + 1;
            }
        }
    }
}
void reset_visit()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int t;
    int si, sj, di, dj;

    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';
        bfs(si, sj);
        cout << level[di][dj] << endl;
        reset_visit();
    }
    return 0;
}
/*
//*input
3
a1 h8
a1 c2
h8 c3
//*output
6
1
4
*/

// #include <bits/stdc++.h>
// #define pii pair<int, int>
// using namespace std;

// const int N = 1005;
// bool vis[N][N];
// int dis[N][N];
// int n, m;

// vector<pii> path{
//     {-1, 0},
//     {1, 0},
//     {0, -1},
//     {0, 1}};

// bool isValid(int ci, int cj)
// {
//     if (ci >= 0 && ci < n && cj >= 0 && cj < m)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void bfs(int si, int sj)
// {
//     queue<pii> q;
//     q.push({si, sj});
//     dis[si][sj] = 0;
//     vis[si][sj] = true;

//     while (!q.empty())
//     {
//         pii parent = q.front();
//         int pi = parent.first;
//         int pj = parent.second;

//         q.pop();

//         for (int i = 0; i < 4; i++)
//         {
//             pii p = path[i];
//             int ci = pi + p.first;
//             int cj = pj + p.second;

//             if (isValid(ci, cj) && !vis[ci][cj])
//             {
//                 vis[ci][cj] = true;
//                 q.push({ci, cj});
//                 dis[ci][cj] = dis[ci][cj] + 1;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     char matrx[n][m];

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> matrx[i][j];
//         }
//     }

//     int si, sj;
//     cin >> si >> sj;

//     bfs(si, sj);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << dis[i][j];
//         }
//         cout << endl;
//     }
//     // __________
//     return 0;
// }

// #include <bits/stdc++.h>
// #define pi pair<int, int>
// using namespace std;
// const int N = 1005;
// bool vis[N][N];
// int dis[N][N];
// int n, m;
// vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// bool isValid(int cI, int cJ)
// {
//     if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
//         return true;
//     else
//         return false;
// }
// void bfs(int si, int sj)
// {
//     queue<pi> q;
//     q.push({si, sj});
//     dis[si][sj] = 0;
//     vis[si][sj] = true;
//     while (!q.empty())
//     {
//         pi parent = q.front();
//         int pI = parent.first;
//         int pJ = parent.second;
//         q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             pi p = path[i];
//             int cI = pI + p.first;
//             int cJ = pJ + p.second;
//             if (isValid(cI, cJ) && !vis[cI][cJ])
//             {
//                 vis[cI][cJ] = true;
//                 q.push({cI, cJ});
//                 dis[cI][cJ] = dis[pI][pJ] + 1;
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     char a[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     int si, sj;
//     cin >> si >> sj;
//     bfs(si, sj);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << dis[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }