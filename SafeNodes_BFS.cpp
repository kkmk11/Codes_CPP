// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].

// input=7
// 7
// 0 1
// 0 2
// 1 2
// 1 3
// 2 5
// 3 0
// 4 5
// output=[2, 4, 5, 6]


//TOPOLOGICAL SORT

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,op;
    cin>>n>>op;
    unordered_map<int,vector<int>> m;
    unordered_map<int,vector<int>> rm;
    vector<int> indg(n,0);
    for(int i=0;i<op;i++){
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
    }
    for(int i=0;i<n;i++){
        for(auto x:m[i]){
            rm[x].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        for(auto x:rm[i]){
            indg[x]++;
        }
    }
    queue<int> q;
    for(int i=0;i<indg.size();i++){
        if(indg[i]==0){
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        res.push_back(front);
        for(auto x:rm[front]){
            indg[x]--;
            if(indg[x]==0){
                q.push(x);
            }
        }
    }
    sort(res.begin(),res.end());
    for(int i:res){
        cout<<i<<" ";
    }
}
