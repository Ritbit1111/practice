/* 
    Initiation time: 09/07/2023 07:04
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
    Problem Statement:
    You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int findElementOfRank(int arr[], int n, int rank){
    priority_queue<int> q;
    // for (int x:arr)q.push(x);
    for (size_t i = 0; i < n; i++) { q.push(arr[i]); }
    while (n-rank > 0){
        q.pop();
        rank++;
    }
    return q.top();
}

int BruteForce(int arr[], int n) {
    unordered_set<int> s(arr, arr+n);
    for (int i=1;i<=n;i++){
        if (s.find(i)==s.end())return i;
    }
    return n+1;
}

int missingNumber(int arr[], int n) 
{ 
    // return BruteForce(arr, n);
    for (int i=0;i<n;i++) cout<<arr[i]<<", ";lc
    int pos=0, negCount=0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i]<=0){
            // cout<<arr[i]<<", "<<pos;lc
            negCount++;
            while(pos < i){
                // cout<<"Inside while "<<pos;lc
                if (arr[pos]>0) {
                    swap(arr[pos], arr[i]);
                    pos++;
                    break;
                }
                pos++;
            }
        }
    }
    for (int i=0;i<n;i++) cout<<arr[i]<<", ";lc
    for (int i=negCount;i<n;i++){
        if (abs(arr[i])+negCount<=n){
            if(arr[abs(arr[i]) + negCount - 1]>0) arr[abs(arr[i]) + negCount - 1] *= -1;
        }
    }
    // for (int i=0;i<n;i++) cout<<arr[i]<<", ";lc
    for (int i=negCount;i<n;i++){
        if (arr[i]>0)return i-negCount+1;
    }
    return n-negCount+1;
} 

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<missingNumber(arr, n);
    return 0;
}