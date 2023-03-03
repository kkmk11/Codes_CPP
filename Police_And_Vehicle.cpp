// KCR Chief Minister of Telangana Government has passed a new G.O to Telangana 
// police for safety of Telangana people. In this regard he announced new Vehicles 
// to be released for all the stations working for this mission especially.

// Here we have a 2D mesh, there are P police officers and V vehicles, with P<=V.
// Each police officer and vehicle is a 2D coordinate on this mesh.
// Here the government has assigned a unique vehicle to each police officer.

// Now create a method which prints the minimum possible sum of distances between 
// each police officer and their assigned vehicle.

// Here the distance is between police officer Pi and vehicle Vi assigned to him.
// And distance between Pi, Vi is calculated as follows: |Pi.x - Vi.x| + |Pi.y - Vi.y|


// Input Format:
// -------------
// Line-1: Two integers P and V, number of police officers and vehicles.
// Next P lines: Two space separated integers co-ordinates of Police officers.
// Next V lines: Two space separated integers co-ordinates of Vehicles.

// Output Format:
// --------------
// Print an integer, the minimum possible sum of distances.


// Sample Input-1:
// ---------------
// 3 3
// 0 1		// co-ordinates of police 
// 1 2
// 1 3
// 4 5		// co-ordinates of vehicles
// 2 5
// 3 6

// Sample Output-1:
// ----------------
// 17


// Sample Input-2:
// ---------------
// 2 2
// 0 0		// co-ordinates of police
// 2 1
// 1 2		// co-ordinates of vehicles
// 3 3

// Sample Output-2:
// ----------------
// 6








#include<bits/stdc++.h>
using namespace std;

int mini=INT_MAX;
void solve(vector<vector<int>> &p,vector<vector<int>> &v,int ind,int sum,vector<bool> &visited){
    if(ind==p.size()){
        mini=min(mini,sum);
        return;
    }
    for(int i=0;i<v.size();i++){
        if(visited[i]==false){
            visited[i]=true;
            solve(p,v,ind+1,sum+abs(p[ind][0]-v[i][0])+abs(p[ind][1]-v[i][1]),visited);
            visited[i]=false;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> p;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    vector<bool> visited(m,false);
    int sum=0;
    solve(p,v,0,sum,visited);
    cout<<mini;
}
