// Your playing a game, the game contains m*n grid.
// Each cell in the grid represent the health points.
// You can move one step either downwads or rightwards only.
// Whenever you visit a cell in the grid, you will lose the 
// same health points of the cell.

// You will start at (0,0) cell of the grid and have to reach (m-1)*(n-1) cell.
// Your task is to minimize the loss of overall health points.

// Input Format:
// -------------
// Line-1: Two integers M and N.
// Next M lines: N space separated integers, health points in each row of the grid.

// Output Format:
// --------------
// Print an integer, minimal loss of overall health points.


// Sample Input-1:
// ---------------
// 3 3
// 1 3 1
// 1 5 1
// 4 2 1

// Sample Output-1:
// ----------------
// 7

// Explanation:
// ------------
// start at cell(0,0) =>  1→3→1→1→1 minimizes the loss of health points.


// Sample Input-2:
// ---------------
// 4 4
// 8 6 9 3
// 7 6 2 1
// 5 5 7 9
// 8 9 6 2

// Sample Output-2:
// ----------------
// 34

// Explanation:
// ------------
// start at cell(0,0) =>  8→6→6→2→1→9→2 minimizes the loss of health points.





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nums(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=nums[i][j];
            }
            else if(i==0 && j!=0){
                dp[i][j]=nums[i][j]+dp[i][j-1];
            }
            else if(i!=0 && j==0){
                dp[i][j]=nums[i][j]+dp[i-1][j];
            }
            else {
                dp[i][j]=nums[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n-1][m-1];
}
