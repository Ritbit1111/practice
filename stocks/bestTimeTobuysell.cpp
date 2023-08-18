/* 
    Initiation time: 05/07/2023 20:51
    Author: Ritesh Kumar
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int maxProfit(vector<int>& prices) {
    int buy=0, sell=1; 
    while(prices[buy]>prices[sell]){
        buy++;sell++;
    }
    int sellPrice = prices[sell];
    int buyPrice = prices[buy];
    int initProfit = sellPrice - buyPrice;
    while(buy<prices.size() && sell<prices.size()){
        if 
    }
}

int main()
{
    vector<int> prices{7,1,5,3,6,4};    
    cout<<maxProfit(prices);
    return 0;
}