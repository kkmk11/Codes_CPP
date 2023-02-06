// Chitti(ROBO) is busy in turning the people into chittis(ROBOS) by surrounding them.
// In a room there are n*n boxes occupied by ROBOS and people.
//    1.A person will be turned into ROBO if he is surrounded by all ROBOs. 
//    2.A person will not be turned into ROBO if he is on the edge of the room
//      and all the connected people to him (directly or indirectly) are also not to be turned.
//  Return the n*n boxes after conversion.
 
// Input Format
// -------------
// Line-1:integer n represent the n*n boxes of the room..
// Next n lines:Each line of string consists of combination of 'X'(represents ROBO) and 'O'(represents a person)
   
// Output Format:
// --------------
// Print n*n space seperated values after conversion.
  
   
// Sample Input-1:
// ---------------
// 4
// XXXX
// XOOX
// XXOX
// OXXX
   
// Sample Output-1:
// ----------------
// X X X X 
// X X X X 
// X X X X 
// O X X X 
   
// Explanation:
// ------------
// The people at second row and third row are converted to ROBOs as they are surrounded by ROBOs.
// But the person at fourth row is safe as he is on edge.
  
   
// Sample Input-2:
// ---------------
// 5
// XOOOX
// XXXXX
// XOXXX
// XXXOX
// OXXXX
  
// Sample Output-2:
// ----------------
// X O O O X 
// X X X X X 
// X X X X X 
// X X X X X 
// O X X X X 


#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid,int i,int j,vector<vector<int>> &visited){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='X' || visited[i][j]==1){
        return;
    }
    visited[i][j]=1;
    dfs(grid,i,j+1,visited);
    dfs(grid,i+1,j,visited);
    dfs(grid,i-1,j,visited);
    dfs(grid,i,j-1,visited);
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            grid[i][j]=s[j];
        }
    }
    vector<vector<int>> visited(n,vector<int> (n,0));
    for(int i=0;i<grid.size();i++){
        if(grid[i][0]=='O'){
            dfs(grid,i,0,visited);
        }
        if(grid[i][grid[0].size()-1]=='O'){
            dfs(grid,i,grid[0].size()-1,visited);
        }
    }
    for(int j=0;j<grid[0].size();j++){
        if(grid[0][j]=='O'){
            dfs(grid,0,j,visited);
        }
        if(grid[grid.size()-1][j]=='O'){
            dfs(grid,grid[0].size()-1,j,visited);
        }
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='O' && visited[i][j]==0){
                grid[i][j]='X';
            }
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
