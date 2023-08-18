/* 
    Initiation time: 07/07/2023 10:19
    Author: Ritesh Kumar
    Problem Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
    Problem Statement:
    A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
    You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
    Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
    Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

int maxConsecutiveAnswersTorF(string answerKey, int k, char x) {
    int left=0, right=0, countInWindow=0;        
    int ans=0;
    while(right<answerKey.length()){
        countInWindow += (answerKey[right]==x);
        while(countInWindow>k){
            countInWindow-=(answerKey[left]==x);
            left++;
        }
        ans = max(ans, right-left+1);
        right++;
    }
    return ans;
}
int maxConsecutiveAnswers(string answerKey, int k) {
    int ans1 = maxConsecutiveAnswersTorF(answerKey, k, 'F');
    int ans2 = maxConsecutiveAnswersTorF(answerKey, k, 'T');
    return max(ans1, ans2);
}
int main()
{
    string s = "TTFF";
    int k = 2;
    cout<< maxConsecutiveAnswers(s, k);
    return 0;
}