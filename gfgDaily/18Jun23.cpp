#include <iostream>
#include <vector>

using namespace std;

// void printVec(vector<int> &vec, string name){
//     cout<<"*******************************";
//     cout<<"Vector "<<name<<endl;
//     for (int i:vec){
//         cout<<i<<", ";
//     }
//     cout<<endl;
// }
int distributeTicket(int N, int K) {
    if (K>N)return N;
    int parts = N/K;
    int remainder = N%K;
    if (parts%2!=0){
        // num will be parts * K + remainder
        if (remainder>0) return (parts/2+1) * K + 1;
        return (parts/2+1) * K;
    }
    if (remainder>0) return (parts/2) * K + remainder;
    return (parts/2) * K + 1;
}

int main(){
    int N = 14;
    int k = 1;
    int last = distributeTicket(N, k);
    cout<<last;
}