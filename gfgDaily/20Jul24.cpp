/* 
    Initiation time: 20/07/2023 18:21
    Author: Ritesh Kumar
    Problem Link: https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
    Problem Statement:
    Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S.
    If there is no non-repeating character, return '$'.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

char nonrepeatingCharacter(string S)
{
    unordered_map<char, int> mp;
    for (int i=0;i<S.length();i++){
        mp[S[i]]+=1;
    }
    for (int i=0;i<S.length();i++){
        if (mp[S[i]]==1){
            return S[i];
        }
    }
    return '$';
    
}
char nonrepeatingCharacter2(string A){
    char ans;
    vector<int> vis(26, 0);
    queue<int> q;
    for (int i = 0; i < A.size(); i++)
    {
        vis[A[i] - 'a']++;
        if (vis[A[i] - 'a'] == 1)
        {
            q.push(A[i]);
        }
        while (!q.empty() && vis[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans = '$';
        }
        else
        {
            ans = q.front();
        }
    }
    return ans;
}
int main()
{
    string S="hihere";
    cout<<nonrepeatingCharacter(S);
    return 0;
}