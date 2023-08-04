// Question: You are given an array of N positive integers. The next line will contain
// an integer K. You need to tell whether there exists more than one occurrence of K
// in that array or not. If there exists more than one occurrence of K print YES,
// Otherwise print NO.
// See the sample input-output for more clarification.
// The given array will be sorted in increasing order. And it is guaranteed that at least
// one occurrence of K will exist. You must solve this in O(logn) complexity.

#include <bits/stdc++.h>
using namespace std;

void find_duplicate(int arr[], int val, int l, int r, int mid)
{
    if (l > r)
    {
        return;
    }

    if (arr[mid] == val)
    {
        if (arr[mid + 1] == arr[mid] || arr[mid - 1] == arr[mid])
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        return;
    }
    else if (arr[mid] < val)
    {
        find_duplicate(arr, val, mid + 1, r, (mid + 1 + r) / 2);
    }
    else
    {
        find_duplicate(arr, val, l, mid - 1, (l + mid - 1) / 2);
    }
};

int main()
{
    int n;
    cin >> n;
    int arrN[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arrN[i];
    }

    int k;
    cin >> k;

    int l = 0, r = n - 1;
    int mid = (l + r) / 2;

    find_duplicate(arrN, k, l, r, mid);

    // __________
    return 0;
}