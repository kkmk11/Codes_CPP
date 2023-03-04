// Viraj Aanand is a wedding planner, He ordered his assistant to decorate a wall.
// The decorator plans to decorate the wall with two different colored balloons.
// The wall size is M*N, The decorator can decorate the wall using M*N balloons
// the balloons are blue or white in color.

// Blue colored ballons represented with digit-1 and 
// White colored ballons represented with digit-0.

// The blue colored balloons forms different shapes, that are connected 4 directonally.
// The directons are upwards, downwards, left, and right. Viraj Aanand got an idea to 
// count the unique shapes formed by blue colored ballons.

// You will be given the decorated wall as a matrix wall[][].
// Your task is to help, Viraj Aanand to count the unique shapes.

// Input Format:
// -------------
// Line-1: Two space separated integers M and N, size of the wall.
// Next M lines: N space separated integers, either 0 or 1.

// Output Format:
// --------------
// Print an integer, Number of distinct shapes formed by blue balloons.


// Sample Input-1:
// ---------------
// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 0 1 1
// 0 0 0 1 1

// Sample Output-1:
// ----------------
// 1


// Sample Input-2:
// ---------------
// 5 5
// 1 1 0 1 1
// 1 0 0 0 1
// 0 0 0 0 0
// 1 0 0 0 1
// 1 1 0 1 1

// Sample Output-2:
// ----------------
// 4





#include <bits/stdc++.h>
using namespace std;

set<vector<vector<int>>> res;
void dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int i,int j,int x,int y,vector<vector<int>> &v){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==0){
        return;   
    }
    visited[i][j]=true;
    v.push_back({x-i,y-j});
    dfs(grid,visited,i+1,j,x,y,v);
    dfs(grid,visited,i,j+1,x,y,v);
    dfs(grid,visited,i-1,j,x,y,v);
    dfs(grid,visited,i,j-1,x,y,v);    
}
int countDistinctIslands(vector<vector<int>>& grid) {
    vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1 && visited[i][j]==false){
                vector<vector<int>> v;
                dfs(grid,visited,i,j,i,j,v);
                res.insert(v);
            }
        }
     }
    return res.size();
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>grid[i][j];
        }
    }
    cout<<countDistinctIslands(grid);
}
