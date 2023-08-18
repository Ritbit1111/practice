#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_set>


using namespace std;
void printVec(vector<int> &vec, string name){
    cout<<"*******************************";
    cout<<"Vector "<<name<<endl;
    for (int i:vec){
        cout<<i<<", ";
    }
    cout<<endl;
}

int sumSqr(int n);
bool IsHappy(int n);

int nextHappy(int N){
        // code here
        int n = N+1;
        while(1){
            if(IsHappy(n))return n;
            n+=1;
        }
        return 0;
}

bool IsHappy(int n){
    unordered_set<int> over({1, 4, 16, 37, 58, 89, 145, 42, 20});
    while(over.find(n)==over.end())n = sumSqr(n);
    return n==1?true:false;
}

int sumSqr(int n){
    int sum = 0;
    while(n){
        int rem = n%10;
        sum  += rem * rem;
        n = n / 10;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    // char ch='\0';
    // vector<int> v;
    // v.push_back(n);
    // while(scanf("%c", &ch)){
    //     if (ch=='q')break;
    //     cout<<endl;
    //     cout<<"Sum of sqr of "<<n<< ": ";
    //     n = sumSqr(n);
    //     v.push_back(n);
    //     cout<<n<<endl;
    // }
    // printVec(v, "Final");
    cout<<nextHappy(n);
    return 0;
}
