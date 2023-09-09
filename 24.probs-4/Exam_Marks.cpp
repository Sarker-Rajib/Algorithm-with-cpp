#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int marks[n];
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }

        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += marks[i];
        }

        if (totalSum % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            int subsetSum = (m + totalSum) / 2;

            int dp[n + 1][subsetSum + 1];

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= subsetSum; j++)
                {
                    dp[i][j] = 0;
                }
            }

            dp[0][0] = 1;

            for (int i = 0; i <= n; ++i)
            {
                for (int j = 0; j <= subsetSum; ++j)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= marks[i - 1])
                    {
                        dp[i][j] += dp[i - 1][j - marks[i - 1]];
                    }
                }
            }

            cout << dp[n][subsetSum];
        }
    }

    return 0;
}
