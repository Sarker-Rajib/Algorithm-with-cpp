#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(string a, int n, string b, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (a[n - 1] == b[m - 1])
    {
        int ans = lcs(a, n - 1, b, m - 1);
        return dp[n][m] = 1 + ans;
    }

    else
    {
        int ops1 = lcs(a, n - 1, b, m);
        int ops2 = lcs(a, n, b, m - 1);
        int ans = max(ops1, ops2);
        return dp[n][m] = ans;
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << lcs(a, a.size(), b, b.size());

    // _____
    return 0;
}

/*
abcfgr
acfdgr
*/