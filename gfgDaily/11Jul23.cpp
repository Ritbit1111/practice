/* 
    Initiation time: 11/07/2023 09:06
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1
    Problem Statement:
    Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained while traversing the matrix spirally. You need to complete the method findK which takes four arguments the first argument is the matrix A and the next two arguments will be n and m denoting the size of the matrix A and then the forth argument is an integer k. The function will return the kth element obtained while traversing the matrix spirally.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007
#define MAX 1000

int findK(int a[MAX][MAX], int n, int m, int k) {
    // Your code goes here.
    int s1 = m, s2 = n;
    int offset_row = 0, offset_col = 0;
    int ans = a[0][0];
    while (k > 0) {
        if (k<=s1) return a[offset_row][offset_col+k-1];
        k = k-s1;
        if (k<=s2-1) return a[offset_row+k][m-offset_col-1];
        k = k-s2+1;
        if (k<=s1-1) return a[n-offset_row-1][m-offset_col-k-1];
        k = k-s1+1;
        if (k<=s2-2) return a[n-offset_row-k-1][offset_col];
        k = k-s2+2;
        s1-=2;s2-=2;
        offset_col++;
        offset_row++;
    }
    return ans;
}
int main()
{
    int n = 5, m = 6, k = 4;
    int A[MAX][MAX] = {{1,2,3, 4, 5, 6}, {16, 17, 18, 19, 20, 7}, {15, 24, 23, 22, 21, 8}, {14, 13, 12, 11, 10, 9}, {15, 14, 13, 12, 11, 10}};
    for (int i=1;i<=n*m;i++){
        cout<<findK(A, n, m, i);lc
    }
    return 0;
}
