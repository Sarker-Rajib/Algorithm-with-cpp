/*
Problem Statement

You will be given a chessboard of NxM size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K(Ki and Kj), and the queen's cell Q(Qi and Qj). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below:image

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain Ki and Kj.
Third line of each test case will contain Qi and Qj.
Constraints

1 <= T <= 100
1 <= N, M <= 100
0 <= Ki, Qi < N
0 <= Kj, Qj < M
Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print -1.
Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1
*/