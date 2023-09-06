#include <bits/stdc++.h>
using namespace std;

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

    if (set[n - 1] <= s)
    {
        bool opt1 = subset_sum(n - 1, set, s - set[n - 1]);
        bool opt2 = subset_sum(n - 1, set, s);
        return opt1 || opt2;
    }
    else
    {
        return subset_sum(n - 1, set, s);
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