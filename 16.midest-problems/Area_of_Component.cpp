/*
Problem Statement

You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-)
where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).
The area of a component is the number of dots(.) in that component that can be accessible.
You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format
First line will contain N and M.
Next you will be given the 2D matrix.
Constraints

1 <= N, M <= 1000
Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1
*/

#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1005;
char matrx[N][N];
bool vis[N][N];
int dis[N][N];
int n, m;

vector<pii> path{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m && matrx[ci][cj] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int count = 1;

    for (auto d : path)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            count += dfs(ci, cj);
        }
    }

    return count;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrx[i][j];
        }
    }

    int minV = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && matrx[i][j] == '.')
            {
                int x = dfs(i, j);
                if (minV > x)
                {
                    minV = x;
                }
            }
        }
    }

    if (minV == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << minV;
    }
    // _____
    return 0;
}