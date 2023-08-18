/* 
    Initiation time: 08/07/2023 14:10
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
    Problem Statement:
    Given an array arr[] of n integers. Check whether it contains a triplet that sums up to zero. 
    Note: Return 1, if there is at least one triplet following the condition else return 0.


*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

bool isTwoSum(int arr[], int startPos, int size, int target){
    for (size_t i = startPos; i < size; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {
            printf("i:%d, j:%d, %d, %d\n", i, j, arr[i], arr[j]);
            if (arr[i]+arr[j]==target)return true;
        }
    }
    return false;
}

bool is3zeros(int arr[], int n){
    int zeroCount=0;
    for (size_t i = 0; i < n; i++)
    {
        if(arr[i]==0)zeroCount++;
        if (zeroCount>2)return true;
    }
    return false;
}

bool findTriplets(int arr[], int n)
{
    if (is3zeros(arr, n))return true;
    sort(arr, arr+n);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";lc
    for(int i=0;i<n;i++){
        if (arr[i]>-1)return false;
        // cout<<i;lc
        if (isTwoSum(arr, i+1, n, -1*arr[i]))return true;
    }
    return false;
}

int main()
{
    int arr[] = {4,-16,43,4,7,-36,18};
    cout<<findTriplets(arr, 7);
    return 0;
}