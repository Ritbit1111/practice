/* 
    Initiation time: 16/07/2023 10:08
    Author: Ritesh Kumar
    Problem Link: https://cses.fi/problemset/task/1617/
    Problem Statement:
    Your task is to calculate the number of bit strings of length n .
    For example, if n=3
    , the correct answer is 8
    , because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int mod(long long a){
    if(a>=MOD){
        a-=MOD;
    }
    return a;
}

int power(int base, int exp){
    int result=1;
    long long powersofbase=base;
    while(exp>0){
        // if (exp%2==1)result = (result*powersofbase)%MOD;
        if (exp%2==1)result = mod((result*powersofbase));
        powersofbase = mod(powersofbase*powersofbase);
        exp = exp/2;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << power(2, n);
    return 0;
}