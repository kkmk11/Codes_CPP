// You are attending a mathematical riddle contest,you are given an integer n and an array of  integer numbers, you have to form a triangle of n rows with those integer numbers(first row contains 1 number, second row contains 2 numbers third row contains 3 numbers, and n the row contains n numbers, order of number should not be changed) and find the minimum path sum from top to bottom.Do this task by using your java programming skills.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// you have to return the minimum sum from top to bottom.

// input format : an integer n (number of rows)
//                1+2+3+....(n-1)+n number of integers(i.e if n =4 then input 10 number of integers as 1+2+3+4=10)
// output format : an integer number 

// Example 1:

// Input: triangle =4 (number of rows) 
//        2 3 4 6 5 7 4 1 8 3
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.
// Example 2:

// Input: 1
//        -10
// Output: -10

// Example 3:
// input =5
// 1 2 3 4 5 6 7 8 9 10 -1 -2 -3 -4 -5
// output = 12
 
// Constraints:
// 1 <= triangle.length <= 200
// tringle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int> (n,INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>nums[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[i][j]!=INT_MAX){
                if(i==0 && j==0){
                    dp[i][j]=nums[i][j];
                }
                else if(i==0 && j!=0){
                    dp[i][j]=nums[i][j];
                }
                else if(i!=0 && j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+nums[i][j];
                }
                else if(i!=0 && j==n-1){
                    dp[i][j]=dp[i-1][j-1]+nums[i][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+nums[i][j];
                }
            }
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,dp[n-1][i]);
    }
    cout<<mini;
}
