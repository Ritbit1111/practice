#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVec(vector<int> &vec, string name){
    cout<<"Vector "<<name<<": ";
    for (int i=0;i<vec.size();i++){
        cout<<vec[i]<<", ";
    }
    cout<<endl;
}
void printArr(long long arr[], int n, string name){
    cout<<"Array "<<name<<": ";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

int sumOfNaturals(int n) {
        // code here
        long ans = n * (n+1)/2;
        return ans%(1000000007);
}

int main(){
    cout<<sumOfNaturals(50);
    return 0;
}