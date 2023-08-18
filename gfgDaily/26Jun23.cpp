// Calculate nCr
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ( a * b ) % c = ((k1c + x) * (k2c + y)) % c = (k1k2c2 + (k1y + k2x)c + (xy)) % c = (xy)%c  = ((a%c)*(b%c))%c
// (10 * 12) % 4
int nCr(int n, int r){
    return 0; 
}

int main(){
    int n = 10, r = 5;
    cout<<nCr(n, r);
    return 0;
}