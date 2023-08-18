/* 
    Initiation time: 05/07/2023 13:21
    Author: Ritesh Kumar
    Problem Link:
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int method1(vector<int>& nums) {
    bool allOnesFlag=true;
    for (auto i=nums.begin(); i!=nums.end();i++){
        if (*i==0)allOnesFlag=false;
    }
    if (allOnesFlag)return nums.size()-1;
    int count = 0;
    vector<int> countOnes(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1){
            count++;
        }
        else{
            countOnes[i] = count;
            count = 0;
        }
    }
    count = 0;
    for (int i = nums.size()-1; i > 0 ; i--)
    {
        if (nums[i] == 1){
            count++;
        }
        else{
            countOnes[i] += count;
            count = 0;
        }
    }
    // for(int i=0;i<countOnes.size();i++){
    //     cout<<countOnes[i]<<" ";
    // }lc
    // return 0;
    return *max_element(countOnes.begin(), countOnes.end());

}
int method2(vector<int>& nums) {
    int head=0, tail=0, zeros=0, ans=0;
    zeros = int(nums[head]==0);
    while(head<nums.size()){
        ans = max(ans, head-tail);
        head++;
        if (head==nums.size())break;
        zeros += nums[head]==0;
        while(zeros>1){
            if (nums[tail]==0){
                zeros--;
            }
            tail++;
        }
    }
    return ans;
}
int longestSubarray(vector<int>& nums) {
    // method1(nums);
    return method2(nums);
}

int main()
{
    vector<int> v{1, 1, 0, 1, 1};
    lc
    cout<<longestSubarray(v);
    return 0;
}