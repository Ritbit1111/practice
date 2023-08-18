#include <bits/stdc++.h>

using namespace std;

int setSetBit(int x, int y, int l, int r){
    int mask = (1<<(l-1)) * ((1<<(r-l+1))-1);
    int ynew = y & mask;
    return x | ynew;
}

unsigned int getFirstSetBit(int n)
{
    // Your code here
    if (n==0)return 0;
    unsigned int ans=0;
    for(int i=1;i<32;i++){
        if ((n&1)==1) return i;
        n = (n>>1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // int l = 26, r=32, x=47156, y=7885;
    // cout<<setSetBit(x, y, l, r);
    // cout<<setSetBit(44, 3, 1, 5);
    cout<<getFirstSetBit(3365);
    // cout<<endl<<uint(~0);
    // cout<<endl<<UINT_MAX;
    cout<<endl<<0xffffffff;
    cout<<"This works";
    return 0;
}
