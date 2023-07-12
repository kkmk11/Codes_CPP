// Mr.Edwards is in hunt of the treasure, the treaure is inside the locker of 
// a room where the floor of the room is in square shape. 
// The floor of size N*N, and it is decorated two different colored tiles,
// white color (0) tiles and black color (1) tiles.

// Initially, Mr Edwards is at (0,0) tile and the treasure is at (N-1, N-1) tile, 
// and both the tiles are white colored.
// The rules to reach the treasure are as follows:
//     - He can move only one step at a time to the adjacent tile.
//     - The adjacent tile can be adjacent horizontal,vertical or diagonal.
//     - He need to step on only white colored tile.
    
// Your task is to help Mr Edwards to reach the Treasure, and 
// print the minimum number of steps required to reach the treasure.
// If it is not possible to reach the treasure, print -1.

// Input Format:
// -------------
// Line-1: An integer N, size of the floor N*N.
// Next N lines: N space separated integers, the floor arragement.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 4
// 0 0 0 1
// 1 0 1 1
// 0 1 1 0
// 1 0 0 0

// Sample Output-1:
// ----------------
// 6


// Sample Input-2:
// ---------------
// 5
// 0 0 1 1 1
// 0 1 0 1 0
// 0 1 1 0 1
// 0 1 0 1 1
// 1 0 1 0 0

// Sample Output-2:
// ----------------
// 7




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> nbrs={{0,1},{1,1},{1,0},{1,-1},{-1,-1},{-1,1},{0,-1},{-1,0}};
    queue<pair<vector<int>,int>> q;
    q.push({{0,0},1});
    while(!q.empty()){
        pair<vector<int>,int> front=q.front();
        q.pop();
        vector<int> v=front.first;
        int count=front.second;
        for(auto nbr:nbrs){
            int r=v[0]+nbr[0];
            int c=v[1]+nbr[1];
            if(r==n-1 && c==n-1 && grid[r][c]==0){
                cout<<count+1;
                exit(0);
            }
            if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0){
                q.push({{r,c},count+1});
                grid[r][c]=1;
            }
        }
    }
    cout<<-1;
}
