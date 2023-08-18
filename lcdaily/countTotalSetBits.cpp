// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

short SetBits[(int)1e6+1];
short SumSetBits[(int)1e6+1];

void fillPreProcess(int x){
    SetBits[0] = 0;
    SetBits[1] = 1;
    SumSetBits[0] = 0;
    SumSetBits[1] = 1;
    int divider = 2;
    for (int i=2;i<=x;i++){
        if (i/divider > 1)divider *= 2;
        SetBits[i] = SetBits[i%divider] + 1;
        SumSetBits[i] = SetBits[i] + SumSetBits[i-1];
    }
    for (int i=0; i<=x; i++){
        cout<<SetBits[i]<<", ";
    }
    cout<<endl;
    cout<<"Sums:"<<endl;
    for (int i=0; i<=x; i++){
        cout<<SumSetBits[i]<<", ";
    }
    cout<<endl;
}

int countSetBits(int A){
    int count = 0;
    while(A){
        A = A & (A-1);
        count++;
    }
    return count;
}

int solveEarlier(int A) {
    fillPreProcess(A);
    int sum = 0;
    int MD = int(1e9 + 7);
    for (int i=0;i<A+1;i++){
        sum = (sum + SetBits[i]) % MD;
        // sum = (sum + countSetBits(i)) % MD;
    }
    return sum;
}

int getIthSetBitCount(int A, int i){
    int whole = (((A+1)>>i)<<(i-1));
    // int residue = (((A+1) % (1<<i))/(1<<(i-1))) % (1<<(i-1));
    int residue = (A+1)%(1<<i);
    if (residue > (1<<(i-1))){
        residue = residue%(1<<(i-1));
    }
    else residue = 0;
    cout<<"A, i: "<<A<<", "<<i<<", Whole, Residue: "<<whole<<", "<<residue<<endl;
    return whole + residue;
}

int solve(int A){
    int ans=0, i=1;
    while(i<8){
        int icount = getIthSetBitCount(A, i);
        cout<<i<<": "<<icount<<endl;
        if (icount==0)return ans;
        ans+=icount;
        i++;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    // cout<<endl<<solve(100)<<endl;
    int A = 4;
    cout<<solve(A);
    /* code */
    return 0;
}
