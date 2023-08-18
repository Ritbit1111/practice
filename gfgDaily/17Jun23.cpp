#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVec(vector<int> &vec, string name){
    cout<<"*******************************";
    cout<<"Vector "<<name<<endl;
    for (int i:vec){
        cout<<i<<", ";
    }
    cout<<endl;
}

void insert(queue<int> &q, int k){
    q.push(k);
}
    
int findFrequency(queue<int> &q, int k){
    queue<int> qtemp;
    int count = 0;
    while (q.size() > 0){
        int knum = q.front();
        q.pop();
        if (knum == k)count++;
        qtemp.push(knum);
    }
    while (qtemp.size() > 0){
        int knum = qtemp.front();
        qtemp.pop();
        q.push(knum);
    }
    return count;

}
int main()
{
    queue<int> qq;
    return 0;
}