#include <iostream>
#include <string>

using namespace std;

string maxPalinOdd(string s, int index){
    int left=index, right=index;
    while(left>=0 && right<s.length()){
        if (s[left] != s[right])break;
        left--;right++;
    }
    return s.substr(left+1, right-left-1);
}

string maxPalinEven(string s, int index){
    int left=index, right=index+1;
    string palin="";
    bool flag=false;
    while(left>=0 && right<s.length()){
        if (s[left] != s[right])break;
        else flag = true;
        left--;right++;
    }
    if (flag) palin = s.substr(left+1, right-left-1);
    return palin;
}

string longestPalin (string S) {
    string maxPalin="", mPe, mPo;
    for (int i=0;i<S.length();i++){
        mPe = maxPalinEven(S, i);
        mPo = maxPalinOdd(S, i);
        if (mPe.length()>maxPalin.length())maxPalin = mPe;
        if (mPo.length()>maxPalin.length())maxPalin = mPo;
    }
    return maxPalin;
}  

int main()
{
    string str = "aaaabbaa";
    // for(int i=0;i<str.length();i++){
    //     cout<<i<<": "<<maxPalinOdd(str, i)<<endl;
    // }
    string ansStr = longestPalin(str);
    cout<<ansStr;
    return 0;
}