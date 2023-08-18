#include <iostream>
#include <queue>

using namespace std;
  
long long maxDiamonds(int A[], int N, int K) {
    // code here
    priority_queue<int> pq;
    for (int i=0; i<N; i++)pq.push(A[i]);

    int diamonds, half;
    long sum=0;
    while(K>0){
        diamonds = pq.top();
        pq.pop();
        half = diamonds/2;
        sum += diamonds;
        // cout<<diamonds<<", "<<half<<" \n";
        pq.push(half);
        K--;
    }
    return sum;
}

int main()
{
    int arr[] = {2, 1, 7, 4, 2};
    long sum = maxDiamonds(arr, 5, 3);
    cout<<sum;
}