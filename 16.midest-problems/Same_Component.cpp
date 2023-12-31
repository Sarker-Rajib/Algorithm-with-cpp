/*
You will be given a 2D matrix of size NxM which will contain
only dot(.) and minus(-)
where dot(.) means you can go in that cell and minus(.) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of to cells
- S(si,sj) and D(di,dj).
You need to tell if these cells are in the same component or not
where you can go from S to D.

Input Format
First line will contain N and M.
Next you will be given the 2D matrix.
Next line will contain si and sj.
Last line will contain di and dj.

Constraints
1 <= N, M <= 1000
0 <= si, di < N
0 <= sj, dj < M

Output Format
Output "YES" if those cell are in the same component, "NO" otherwise.

Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0

NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1

YES
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

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (auto d : path)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
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

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si, sj);

    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// #define pii pair<int, int>
// using namespace std;

// const int N = 1005;
// char matrx[N][N];
// bool vis[N][N];
// int n, m;

// vector<pii> path{
//     {-1, 0},
//     {1, 0},
//     {0, -1},
//     {0, 1}};

// bool isValid(int ci, int cj)
// {
//     if (ci >= 0 && ci < n && cj >= 0 && cj < m && matrx[ci][cj] == '.')
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void dfs(int si, int sj)
// {
//     vis[si][sj] = true;

//     for (auto d : path)
//     {
//         int ci = si + d.first;
//         int cj = sj + d.second;
//         if (isValid(ci, cj) && !vis[ci][cj])
//         {
//             dfs(ci, cj);
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> matrx[i][j];
//         }
//     }

//     int si, sj, di, dj;
//     cin >> si >> sj >> di >> dj;

//     dfs(si, sj);

//     if (vis[di][dj])
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     //_______
//     return 0;
// }
