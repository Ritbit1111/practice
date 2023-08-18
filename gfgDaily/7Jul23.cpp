/* 
    Initiation time: 07/07/2023 20:50
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
    Problem Statement:
    Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
    Merge them in sorted order without using any extra space.
    Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;
#define MOD 1000000007

void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    //Find the index of first element in arr1 that need to be swapped
    if (n==0 || m==0)return;
    int count = 0;
    int ptr1 = 0, ptr2 = 0;
    while(count<n){
        if (ptr2<m){
            if (arr1[ptr1] < arr2[ptr2])ptr1++;
            else ptr2++;
        }
        else ptr1++;
        count++;
    }
    if (ptr1 == n)return;
    ptr2 = 0;
    while(ptr1<n){
        swap(arr1[ptr1], arr2[ptr2]);
        ptr1++;ptr2++;
    }
    for (int i=0;i<n;i++)cout<<arr1[i]<<", ";lc
    for (int i=0;i<m;i++)cout<<arr2[i]<<", ";lc
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
} 
int main()
{
    long long arr1[] = {1, 35};
    long long arr2[] = {6,9,13,15,20,25,29,46};
    int n=2, m=8;
    merge(arr1, arr2, n, m);
    for (int i=0;i<n;i++)cout<<arr1[i]<<", ";lc
    for (int i=0;i<m;i++)cout<<arr2[i]<<", ";lc
    return 0;
}