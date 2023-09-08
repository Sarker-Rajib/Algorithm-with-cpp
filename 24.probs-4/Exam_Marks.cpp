// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int marks[n];

//         for (int i = 0; i < n; i++)
//         {
//             cin >> marks[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cout << marks[i];
//         }

//         int dp[n + 1][m + 1];

//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= m; j++)
//             {
//                 dp[i][j] = false;
//             }
//         }

//         dp[0][0] = true;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 0; j <= m; j++)
//             {
//                 dp[i][j] = dp[i - 1][j];
//                 if (marks[i - 1] <= j)
//                 {
//                     dp[i][j] = dp[i - 1][j - marks[i - 1]] || dp[i - 1][j];
//                 }
//             }
//         }

//         // if (dp[n][m])
//         // {
//         //     cout << "YES" << endl;
//         // }
//         // else
//         // {
//         //     cout << "NO" << endl;
//         // }

//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= m; j++)
//             {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }

//     // _____
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1005;

bool dp[MAX_N];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> marks(n);
        for (int i = 0; i < n; i++)
        {
            cin >> marks[i];
        }

        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = m; j >= marks[i]; j--)
            {
                dp[j] = dp[j] || dp[j - marks[i]];
            }
        }

        if (dp[m])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
