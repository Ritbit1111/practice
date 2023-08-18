/* 
    Initiation time: 12/07/2023 20:50
    Author: Ritesh Kumar
    Problem Link: https://leetcode.com/problems/find-eventual-safe-states/
    Problem Statement: 
    There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
    Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
    
*/
#include <bits/stdc++.h>
using namespace std;

#define lc cout<<endl;

#define MOD 1000000007

bool IsSafe(vector<vector<int>>& graph, unordered_set<int>& safeNode, int index){
    if (safeNode.count(index) == 1)
        return true;
    if (graph[index].size() == 0)
    {
        safeNode.insert(index);
        return true;
    }
    for (int i : graph[index])
    {
        if (!IsSafe(graph, safeNode, i))
            return false;
    }
    safeNode.insert(index);
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    unordered_set<int> safeNode;
    for (int i=0;i<graph.size();i++){
        if(IsSafe(graph, safeNode, i))ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = eventualSafeNodes(graph);
    for (int i:ans)cout<<i;
    return 0;
}