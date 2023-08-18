#include<iostream>
using namespace std;

int isDivisible(string s){
	int siz = s.length();
    int sum=0;
    int fac = 1;
    for (int i=siz-1;i>=0;i--){
        sum+=int(s[i]) * fac;
        fac = fac==1?2:1;
    }
    return sum%3==0?1:0;
}

int main(int argc, const char** argv) {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << isDivisible(s) << endl;
    }
    return 0;
}