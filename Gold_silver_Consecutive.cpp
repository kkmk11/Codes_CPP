// A merchant has two types of idols, gold and silver.
// He has arranged the idols in the form of m*n grid, 
// 	- the gold idols are represented as 1's 
// 	- the silver idols are represented as 0's.

// Your task is to find the longest consecutive arrangement of gold idols, 
// The arrangement can be either horizontal, vertical, diagonal or 
// antidiagonal, but not the combination of these.


// Input Format:
// -------------
// Line-1: Two space separated integers m and n, grid size.
// Next m lines : n space separated integers, arrangement of idols.

// Output Format:
// --------------
// Print an integer, longest arranement of gold idols.


// Sample Input:
// ---------------
// 4 5
// 1 0 1 1 1
// 0 1 0 1 0
// 1 0 1 0 1
// 1 1 0 1 1

// Sample Output:
// ----------------
// 4




#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void horizontal(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    horizontal(nums,i+1,j,sum);
    v.push_back(sum);
}
void vertical(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    vertical(nums,i,j+1,sum);
    v.push_back(sum);
}
void diagonal_right(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    diagonal_right(nums,i+1,j+1,sum);
    v.push_back(sum);
}
void diagonal_left(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    diagonal_left(nums,i-1,j+1,sum);
    v.push_back(sum);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                int a=0,b=0,c=0,d=0;
                horizontal(grid,i,j,a);
                vertical(grid,i,j,b);
                diagonal_right(grid,i,j,c);
                diagonal_left(grid,i,j,d);
                int x=*max_element(v.begin(),v.end());
                maxi=max(maxi,x);
                v.clear();
            }
        }
    }
    cout<<maxi;
}
