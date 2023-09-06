#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

void setV()
{
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            dp[i][j] = -1;
        }
    }
}

bool subset_sum(int n, int set[], int s)
{
    if (n == 0)
    {
        if (s == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }

    if (set[n - 1] <= s)
    {
        bool opt1 = subset_sum(n - 1, set, s - set[n - 1]);
        bool opt2 = subset_sum(n - 1, set, s);
        return dp[n][s] = opt1 || opt2;
    }
    else
    {
        return dp[n][s] = subset_sum(n - 1, set, s);
    }
};

int main()
{
    int n;
    cin >> n;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int s;
    cin >> s;

    setV();

    if (subset_sum(n, set, s))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    // _____
    return 0;
}

/*
4
1 2 4 6
9
*/