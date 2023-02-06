// Pranav has a puzzle board filled with square boxes in the form of a grid.
// Some cells in the grid may be empty. '0' - indicates empty, '1' - indicates a box. 

// Pranav wants to find out the number of empty spaces which are completely 
// surrounded by the square boxes (left, right, top, bottom) in the board.

// You are given the board in the form of a grid M*N, filled wth 0's and 1's.
// Your task is to help Pranav to find the number of empty groups surrounded by
// the boxes in the puzzle board.

// Input Format:
// -------------
// Line-1: Two integers M and N, the number of rows and columns in the board.
// Next M lines: contains N space-separated either 0 or 1.

// Output Format:
// --------------
// Print an integer, the number of empty spaces in the puzzle board.


// Sample Input-1:
// ---------------
// 6 7
// 1 1 1 1 0 0 1
// 1 0 0 0 1 1 0
// 1 0 0 0 1 1 0
// 0 1 1 1 0 1 0
// 1 1 1 0 0 1 1
// 1 1 1 1 1 1 1

// Sample Output-1:
// ----------------
// 2


// Sample Input-2:
// ---------------
// 6 6
// 1 1 0 0 1 1
// 1 0 1 1 0 1
// 0 1 0 1 0 0
// 1 1 0 0 0 1
// 0 0 1 0 1 1
// 1 1 0 1 0 0

// Sample Output-2:
// ----------------
// 1


#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &visited){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1 || visited[i][j]==1){
        return;
    }
    visited[i][j]=1;
    dfs(grid,i,j+1,visited);
    dfs(grid,i+1,j,visited);
    dfs(grid,i-1,j,visited);
    dfs(grid,i,j-1,visited);
}
void solve(vector<vector<int>> &grid,int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]==1){
        return;
    }
    grid[i][j]=1;
    solve(grid,i,j+1);
    solve(grid,i+1,j);
    solve(grid,i-1,j);
    solve(grid,i,j-1);
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int> (c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> visited(r,vector<int> (c,0));
    for(int i=0;i<grid.size();i++){
        if(grid[i][0]==0){
            dfs(grid,i,0,visited);
        }
        if(grid[i][grid[0].size()-1]==0){
            dfs(grid,i,grid[0].size()-1,visited);
        }
    }
    for(int j=0;j<grid[0].size();j++){
        if(grid[0][j]==0){
            dfs(grid,0,j,visited);
        }
        if(grid[grid.size()-1][j]==0){
            dfs(grid,grid.size()-1,j,visited);
        }
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0 && visited[i][j]==1){
                grid[i][j]=1;
            }
        }
    }
    int k=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0){
                solve(grid,i,j);
                k++;
            }
        }
    }
    cout<<k;
}
