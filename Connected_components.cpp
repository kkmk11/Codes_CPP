// /*
// There are N cities, and M routes[], each route is a path between two cities.
// routes[i] = [city1, city2], there is a travel route between city1 and city2.
// Each city is numbered from 0 to N-1.
 
// There are one or more Regions formed among N cities. 
// A Region is formed in such way that you can travel between any two cities 
// in the region that are connected directly and indirectly.
 
// Your task is to findout the number of regions formed between N cities. 
 
// Input Format:
// -------------
// Line-1: Two space separated integers N and M, number of cities and routes
// Next M lines: Two space separated integers city1, city2.
 
// Output Format:
// --------------
// Print an integer, number of regions formed.
 
 
// Sample Input-1:
// ---------------
// 5 4
// 0 1
// 0 2
// 1 2
// 3 4
 
// Sample Output-1:
// ----------------
// 2
 
 
// Sample Input-2:
// ---------------
// 5 6
// 0 1
// 0 2
// 2 3
// 1 2
// 1 4
// 2 4
 
// Sample Output-2:
// ----------------
// 1





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,op;
    cin>>n>>op;
    unordered_map<int,vector<int>> m;
    for(int i=0;i<op;i++){
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    vector<bool> visited(n,false);
    queue<int> q;
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            visited[i]=true;
            q.push(i);
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto x:m[front]){
                    if(visited[x]==false){
                        q.push(x);
                        visited[x]=true;
                    }
                }
            }
            c++;
        }
    }
    cout<<c;
}
