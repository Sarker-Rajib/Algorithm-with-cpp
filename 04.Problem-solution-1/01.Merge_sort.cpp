// Question: Write a C++ program that takes N integer numbers and sorts them in
// non-increasing order using Merge Sort.
// You can’t use any built-in function for sorting.

#include <bits/stdc++.h>
using namespace std;

void merge(int numArr[], int l, int r, int mid)
{
    int leftPartSize = mid - l + 1;
    int L[leftPartSize + 1];

    int rightPartSize = r - mid;
    int R[rightPartSize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = numArr[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = numArr[i];
    }

    L[leftPartSize] = INT_MIN;
    R[rightPartSize] = INT_MIN;

    int LP_pointer = 0, RP_pointer = 0;

    for (int i = l; i <= r; i++)
    {
        if (L[LP_pointer] >= R[RP_pointer])
        {
            numArr[i] = L[LP_pointer];
            LP_pointer++;
        }
        else
        {
            numArr[i] = R[RP_pointer];
            RP_pointer++;
        }
    }
};

void merge_sort(int arr[], int l, int r)
{
    if (l == r)
    {
        return;
    }

    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, r, mid);
};

void m_Sort(int arr[], int l, int r)
{
    merge_sort(arr, l, r);
}

int main()
{
    int n;
    cin >> n;

    int num_arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num_arr[i];
    }

    m_Sort(num_arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << num_arr[i] << " ";
    }

    // ______
    return 0;
}