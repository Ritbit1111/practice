#include <bits/stdc++.h>

using namespace std;

bool buddyStrings(string s, string goal) {
    if (s.length()==1)return false;
    if (s==goal){
        unordered_set<char> charset;
        for(auto c=s.begin();c!=s.end();c++){
            if (charset.find(*c)!=charset.end())return true;
            charset.insert(*c);
        }
        return false;
    }
    int i=0,j=s.length()-1;
    for (;i<s.length();i++){
        if (s[i]!=goal[i])break;
    }
    for (;j>=0;j--){
        if (s[j]!=goal[j])break;
    }
    swap(s[i], s[j]);
    if (s==goal)return true;
    return false;
}

int main(int argc, const char** argv) {
    string s1 = "ab";
    string s2 = "ab";
    cout<<buddyStrings(s1, s2);
    return 0;
}