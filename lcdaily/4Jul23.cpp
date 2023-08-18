#include <bits/stdc++.h>

using namespace std;

bool IsSetBit(int x, int pos){
    return ((x>>pos) & 1);
}

int singleNumber(vector<int>& nums) {
    int singleNum=0;
    int numBits[32];
    for (int pos=0;pos<32;pos++){
        numBits[pos] = 0;
    }        
    for(auto num=nums.begin(); num!=nums.end(); num++){
        for (int pos=0;pos<32;pos++){
            numBits[pos] += IsSetBit(*num, pos);
        }        
    }
    for (int pos=0;pos<32;pos++){
        numBits[pos] %= 3;
    } 
    // for (int pos=0;pos<32;pos++){
    //     cout<<numBits[pos]<<" ";
    // } 
    // cout<<endl;
    for (int pos=0;pos<32;pos++){
        singleNum = singleNum + numBits[pos] * (1<<pos);
    }        
    return singleNum;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums{2,2,3,2};
    cout<<endl;
    cout<<singleNumber(nums);
    return 0;
}
