/*
Problem Statement

Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants.

Can you tell if he can select marks from this list in such a way that his total marks add up to 1000?

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain a list A of N marks.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= M <= 1000
1 <= A[i] <= 100; 0 <= i < N
Output Format

Output "YES" if he can obtain perfect score of 1000, "NO" otherwise.
Sample Input 0

3
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
2 900
30 40
Sample Output 0

YES
NO
YES
*/