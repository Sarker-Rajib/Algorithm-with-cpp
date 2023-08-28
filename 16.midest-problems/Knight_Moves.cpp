/*
Problem Statement

You will be given a chessboard of NxM size.
You can move anywhere in the chessboard freely.
You will be given two cells - the knight's cell K(Ki and Kj),
8 8
0 0
7 7
5 6
and the queen's cell Q(Qi and Qj).
You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions.
The directions are given below: image

Input Format
First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain Ki and Kj.
Third line of each test case will contain Qi and Qj.

Constraints
1 <= T <= 100
1 <= N, M <= 100
0 <= Ki, Qi < N
0 <= Kj, Qj < M

Output Format
Output the minimum number of steps for the knight to reach the queen.
If you can't reach to queen, print -1.

Sample Input 0
4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
int n, m;
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
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void initialize()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            level[i][j] = -1;
        }
    }
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        initialize();
        cin >> n >> m;
        int si, sj;
        cin >> si >> sj;

        int di, dj;
        cin >> di >> dj;
        bfs(si, sj);
        cout << level[di][dj] << endl;
        reset_visit();
    }

    // ______
    return 0;
}
