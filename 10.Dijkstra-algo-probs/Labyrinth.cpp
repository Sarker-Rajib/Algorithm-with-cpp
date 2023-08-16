/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/

// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// typedef pair<int, int> pii;
// const int N = 1e3 + 10;
// vector<string> g;
// vector<pii> direc = {{0, -1},
//                      {0, 1},
//                      {-1, 0},
//                      {1, 0}};
// int level[N][N];
// bool visited[N][N];
// pii parent[N][N];

// bool isValid(int i, int j)
// {
//     return (i >= 0 && i < n && j >= 0 && j < m);
// }

// void bfs(int si, int sj)
// {
//     queue<pii> q;
//     q.push({si, sj});
//     visited[si][sj] = true;
//     level[si][sj] = 0;

//     while (!q.empty())
//     {
//         pii upair = q.front();
//         int i = upair.first;
//         int j = upair.second;
//         q.pop();

//         for (auto d : direc)
//         {
//             int ni = i + d.first;
//             int nj = j + d.second;

//             if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
//             {
//                 q.push({ni, nj});
//                 visited[ni][nj] = true;
//                 parent[ni][nj] = {i, j};
//             }
//         }
//     }
// };

// int main()
// {
//     int si, sj, di, dj;

//     cin >> n >> m;

//     for (int i = 0; i < n; i++)
//     {
//         string x;
//         cin >> x;

//         for (int j = 0; j < m; j++)
//         {
//             if (x[j] == 'A')
//             {
//                 si = i, sj = j;
//             }
//             if (x[j] == 'B')
//             {
//                 di = i, dj = j;
//             }
//         }

//         g.push_back(x);
//     }

//     bfs(si, sj);

//     cout << level[di][dj];

//     // __________
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int m, n;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> g;
int visited[N][N];
int level[N][N];
pii parents[N][N];
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool is_valid(int i, int j)
{
    return (i >= 0 && i < m && j >= 0 && j < n);
}
void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    parents[si][sj] = {-1, -1};
    while (!q.empty())
    {
        pii u = q.front();
        int ui = u.first;
        int uj = u.second;
        q.pop();
        for (pii d : direc)
        {
            int vi = ui + d.first;
            int vj = uj + d.second;
            if (is_valid(vi, vj) && !visited[vi][vj] && g[vi][vj] != '#')
            {
                q.push({vi, vj});
                visited[vi][vj] = true;
                level[vi][vj] = level[ui][uj] + 1;
                parents[vi][vj] = {ui, uj};
            }
        }
    }
}
int main()
{
    cin >> m >> n;
    int si, sj, di, dj;
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < n; j++)
        {
            if (x[j] == 'A')
            {
                si = i, sj = j;
            }
            if (x[j] == 'B')
            {
                di = i, dj = j;
            }
        }
        g.push_back(x);
    }
    bfs(si, sj);
    vector<pii> path;
    pii curr = {di, dj};
    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
        while (curr.first != -1 && curr.second != -1)
        {
            path.push_back(curr);
            curr = parents[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                if (path[i - 1].second == path[i].second - 1)
                {
                    cout << "R";
                }
                else
                    cout << "L";
            }
            else
            {
                if (path[i - 1].first == path[i].first - 1)
                {
                    cout << "D";
                }
                else
                    cout << "U";
            }
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}
/*
//*input
5 8
########
#.A#...#
#.##.#B#
#......#
########
//*output
YES
9
LDDRRRRRU
*/