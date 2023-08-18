#include<bits/stdc++.h>

using namespace std;

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
    int head=0, tail=0;
    // Move head and tail to first element < k
    while(a[head]>=k){
        head++;tail++;
    }
    tail++;
    int product = a[head];
    while(tail<n && (a[tail] * product < k))
    {
        product *= a[tail];
        tail++;
    }
    // Move tail to the max distance where product < k
    int ans=0;
    while(head<n)
    {
        ans += tail - head;
        std::cout<<"Head: "<<head<<" Tail: "<<tail<<" Product: "<<product<<" Ans: "<<ans<<endl;
        if (head<tail){
        product = product / a[head];
        head++;
        }
        else{
            head++;
            tail++;
        }
        while ((a[tail] * product < k) && tail < n)
        {
            product *= a[tail++];
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> a{1, 9, 2, 8, 6, 4, 3};
    // vector<int> a{39,40,23,37,25,27,2,36};
    int k=100;
    // int k=25;
    std::cout<<countSubArrayProductLessThanK(a, a.size(), k);
    return 0;
}
