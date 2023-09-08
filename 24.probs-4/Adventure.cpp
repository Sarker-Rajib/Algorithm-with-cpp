#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, s;
        cin >> n >> s;
        int weights[n];
        int values[n];

        for (int i = 0; i < n; ++i)
        {
            cin >> weights[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> values[i];
        }

        int dp[n + 1][s + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (weights[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][s] << endl;
    }

    return 0;
}
