// Given a nokia phone,with the following dialpad.
// 		1 2 3
// 		4 5 6
// 		7 8 9
// 		* 0 #
// And You are given an L band to dial the number,  
// Using the L band you can dial the number as follows, 
// You can start with any digit,
// 	if you are at digit 1, next digit you can choose {6,8}
// 	if you are at digit 2, next digit you can choose {7,9}
// 	if you are at digit 3, next digit you can choose {4,8}
// 	and so on..

// Now your task is to find how many distinct numbers of length N you can dial.

// Note: Numbers should contain only digits, no {* , #}.
// Answer is modulo 1000000007.

// Input Format:
// -----------------
// An integer N, length of numbers
 
// Output Format:
// ------------------
// Print an integer, number of distinct numbers you can dial.


// Sample Input-1:
// ---------------
// 1

// Sample Output-1:
// ----------------
// 10

// Explanation:
// -------------
// To dial a number of length 1, you can dial all digits.


// Sample Input-2:
// ---------------
// 2

// Sample Output-2:
// ----------------
// 20

// Explanation:
// ------------
// To dial a number of length 2, the possible numbers are
// {04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94}

// Sample Input-3:
// ---------------
// 5

// Sample Output-3:
// ----------------
// 240



#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string> m={{0,"46"},{1,"68"},{2,"79"},{3,"48"},{4,"039"},{5,""},{6,"017"},{7,"26"},{8,"13"},{9,"24"}};
long long solve(int n,int ind,vector<vector<int>> &dp){
    if(n==1){
        return 1;
    }
    if(dp[n][ind]!=-1){
        return dp[n][ind];
    }
    long long sum=0;
    for(auto x:m[ind]){
        sum=sum+solve(n-1,x-'0',dp);
        sum=sum%1000000007;
    }
    dp[n][ind]=sum;
    return dp[n][ind];
}
int main(){
    int n;
    cin>>n;
    long long res=0;
    vector<vector<int>> dp(n+1,vector<int> (10,-1));
    for(int i=0;i<=9;i++){
        res=res+solve(n,i,dp);
        res=res%1000000007;
    }
    cout<<res;
}
