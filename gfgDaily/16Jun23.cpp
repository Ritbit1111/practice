#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec, string name){
    cout<<"*******************************";
    cout<<"Vector "<<name<<endl;
    for (int i:vec){
        cout<<i<<", ";
    }
    cout<<endl;
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

void JointSort(int n, vector<int> &locations, vector<int> &time){
    vector<pair<int, int> > jointVec;
    for (int i=0; i<n;i++){
        jointVec.push_back(make_pair(time[i], locations[i]));
    }
    sort(jointVec.begin(), jointVec.end(), comp);
    for (int i=0; i<n;i++){
        locations[i] = jointVec[i].second;
        time[i] = jointVec[i].first;
    }
}

long long getMinTime(int n, vector<int> &locations, vector<int> &types) {
    JointSort(locations.size(), locations, types);
    printVec(locations, "Locas");
    int sum = abs(locations[0]);
    for (int i=1;i<locations.size();i++){
        sum += abs(locations[i] - locations[i - 1]);
        cout<<sum<<endl;
    }
    sum += abs(locations[n-1]);
    return sum;
}


int main() {
    int locsa[] = {-4, -3, 1, -8};
    int timea[] = {4, 2, 4, 5};
    // -3 -> -4 -> 1 -> -8 -> 0
    int n = 4;
    vector<int> locs(locsa, locsa+n);
    vector<int> time(timea, timea+n);
    long long ans = getMinTime(4, locs, time);
    cout<<ans;
    return 0;
    return 0;
}