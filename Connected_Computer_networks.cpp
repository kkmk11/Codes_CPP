
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi]
//  represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
// input = number of nodes n 
// number of edges m
// m number of edges 
// output = integer 

// sample cases:
// input =
// 4
// 3
// 0 1
// 0 2
// 1 2
// output = 1
// case 2:
// input = 6
// 5
// 0 1
// 0 2
// 0 3
// 1 2
// 1 3
// output = 2




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,op;
    cin>>n;
    cin>>op;
    unordered_map<int,vector<int>> m;
    for(int i=0;i<op;i++){
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    queue<int> q;
    vector<int> visited(n,false);
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            visited[i]=true;
            q.push(i);
            c++;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto x:m[front]){
                    if(visited[x]==false){
                        visited[x]=true;
                        q.push(x);
                    }
                }
            }
        }
    }
    if(n-1<=op){
        cout<<c-1;
    }
    else{
        cout<<-1;
    }
}
