#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>


#define MAX 1000
using namespace std;

void printVec(vector<int> &vec, string name){
    cout<<"*******************************";
    cout<<"Vector "<<name<<endl;
    for (int i:vec){
        cout<<i<<", ";
    }
    cout<<endl;
}

long long BinToInt(vector<int> v){
    long long num=0;
    int base = 2;
    size_t n=v.size();
    for(int i=0;i<v.size();i++){
        num+= v[i] * (long long)(pow(base, i)+1e-9);
    }
    return num;
}

vector<int> IntToBin(long long n){
    vector<int> ans;
    while(n){
        ans.push_back(n%2);
        n = n/2;
    }
    return ans;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    unordered_set<long long>once;
    vector<vector<int>> ans;
    for (int i=0;i<row;i++){
        vector<int> vtemp(M[i], M[i]+col);
        long long bti = BinToInt(vtemp);
        if(once.find(bti)==once.end()){
            ans.push_back(vtemp);
            once.insert(bti);
        }
    }
    return ans;
}

int main() {
    return 0;
}