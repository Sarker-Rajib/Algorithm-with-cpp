// Question: You are given two sorted arrays arr1 and arr2 in descending order. Your
// task is to merge these two arrays into a new array result using the merge sort
// technique, but Instead of merging the arrays in ascending order, you need to merge
// them in descending order to create the result array.
// You cannot use stl sort function here

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arrFirst[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arrFirst[i];
    }

    int m;
    cin >> m;
    int arrSecond[m + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> arrSecond[i];
    }

    int nS = n + m;
    int newArray[nS];

    arrFirst[n] = INT_MIN;
    arrSecond[m] = INT_MIN;

    int p1 = 0, p2 = 0;

    for (int i = 0; i <= nS; i++)
    {
        if (arrSecond[p2] <= arrFirst[p1])
        {
            newArray[i] = arrFirst[p1];
            p1++;
        }
        else
        {
            newArray[i] = arrSecond[p2];
            p2++;
        }
    }

    for (int i = 0; i < nS; i++)
    {
        cout << newArray[i] << " ";
    }

    // ______
    return 0;
}