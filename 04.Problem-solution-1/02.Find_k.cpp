// Question: Write a C++ program that takes N integer numbers that are sorted and
// distinct. The next line will contain an integer k. You need to tell whether K exists
// in that array or not. If it exists, print its index otherwise print “Not Found”.
// You must solve this in O(logn) complexity.

#include <bits/stdc++.h>
using namespace std;

void findIndex(int arr[], int val, int l, int r, int mid)
{
    if (l > r)
    {
        cout << "Not Found";
        return;
    }

    if (arr[mid] == val)
    {
        cout << mid;
        return;
    }
    else if (arr[mid] < val)
    {
        findIndex(arr, val, mid + 1, r, (mid + 1 + r) / 2);
    }
    else
    {
        findIndex(arr, val, l, mid - 1, (l + mid - 1) / 2);
    }
};

int main()
{
    int n;
    cin >> n;
    int arrNum[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arrNum[i];
    }

    int k;
    cin >> k;

    int l = 0, r = n - 1;
    int mid = (l + r) / 2;

    findIndex(arrNum, k, l, r, mid);

    // _____
    return 0;
}