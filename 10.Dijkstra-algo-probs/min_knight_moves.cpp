#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
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