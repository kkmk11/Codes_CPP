// Brahmi and his gang was chased by group of police officers, unfortunately 
// they all got locked up in a building consist of M*N rooms in the form of 
// a grid. All the rooms are connected with  the adjacent rooms both horizontally
// and vertically. There are few rooms for them to escape called as safe zones. 

// Now help Brahmi and his gang to reach the safe zones in the building.

// In the Building we have the rooms filled with following values: [0,-1,-2] 
// where, -1 -> Danger zone (they should not enter into it).
// 0 -> Safe Zone (room to escape)
// -2 -> a thief

// Now create a method to print the grid after performing following step: 
// Fill each room with one of the member from The Brahmi and his gang with 
// the distance to its nearest safe zone.
// If it is impossible to reach a safezone, fill with '-2' only.

// Input Format:
// -------------
// Line-1 -> two integers M and N, size of the grid of rooms.
// Next M Lines -> N space separated integers, from this set [-2,-1,0] only.

// Output Format:
// --------------
// Print an integer as result.


// Sample Input-1:
// ---------------
// 4 4
// -2 -1 0 -2
// -2 -2 -2 -1
// -2 -1 -2 -1
// 0 -1 -2 -2

// Sample Output-1:
// ----------------
// 3 -1 0 1
// 2 2 1 -1
// 1 -1 2 -1
// 0 -1 3 4





#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid,int i,int j,int c,int &ans){
    if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1){
        return;
    }
    if(grid[i][j]==0){
        ans=min(ans,c);
        return;
    }
    int temp=grid[i][j];
    grid[i][j]=-1;
    dfs(grid,i+1,j,c+1,ans);
    dfs(grid,i,j+1,c+1,ans);
    dfs(grid,i-1,j,c+1,ans);
    dfs(grid,i,j-1,c+1,ans);
    grid[i][j]=temp;
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
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==-2){
                int ans=INT_MAX;
                dfs(grid,i,j,0,ans);
                if(ans!=INT_MAX){
                    grid[i][j]=ans;
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
