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

void arrange(long long arr[], int n) {
    for (int i=0;i<n;i++){
        arr[i] += n*(arr[arr[i]]%n);
    }
    printArr(arr, n, "Intermediate");
    for (int i=0;i<n;i++){
        arr[i] /= n;
    }
}

int main(){
    long long arr[] = {4,0,2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n, "Initial Arr");
    arrange(arr, n);
    printArr(arr, n, "Final Arr");
}