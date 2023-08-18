/* 
    Initiation time: 06/07/2023 13:11
    Author: Ritesh Kumar
    Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int method1(int target, vector<int>& nums){
    sort(nums.begin(), nums.end());
    for (auto i:nums)cout<<i<<", ";lc
    int sum=0;
    int size = nums.size();
    for (int i = size-1; i >= 0; i--)
    {
        sum += nums[i];
        if (sum>=target)return (size-i);
    }
    return 0;
}

int method2(int target, vector<int>& nums){
    int head=0, tail=0;
    int ans=nums.size()+1;
    int tempSum=nums[0];
    for(;tail<nums.size();tail++){
        while(tempSum<target && head<nums.size()-1){
            head++;
            tempSum += nums[head];
        }
        if (tempSum>=target) ans = min(ans, head-tail+1);
        tempSum -= nums[tail];
    }
    if (ans==nums.size()+1)return 0;
    return ans;
}

int minSubArrayLen(int target, vector<int>& nums) {
    // return method1(target, nums);
    return method2(target, nums);
}

int main()
{
    vector<int> vi{12,28,83,4,25,26,25,2,25,25,25,12};    
    int target = 213;
    cout<<minSubArrayLen(target, vi);
    return 0;
}