#include <iostream>
#include <vector>

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
int matchGame(long long N) {
        // code here
    int ans = N%5;
    return ans==0? -1:ans;
}

int main(){
cout<<matchGame(48);
}