/* 
    Initiation time: 17/07/2023 20:15
    Author: Ritesh Kumar
    Problem Link: https://cses.fi/problemset/task/1618
    Problem Statement:
    Your task is to calculate the number of trailing zeros in the factorial n!.
    For example, 20!=2432902008176640000 and it has 4 trailing zeros.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int countTrailingZeros(int n){
    int countof5=n/5;
    int sums=countof5;
    while(countof5>0){
        countof5 = countof5/5;
        sums += countof5;
    }
    return sums;
}

int main()
{
    int n;
    cin>>n;
    cout<<countTrailingZeros(n);
    return 0;
}