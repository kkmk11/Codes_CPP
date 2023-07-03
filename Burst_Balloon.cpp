// You are playing a shooting game.
// There are N bottles hanging to a rod, i-th bottle numbered bottle[i].

// If you shoot i-th bottle, you will get bottle[i-1]*bottle[i]*bottle[i+1] points.
// The more points you score, the more rewards you can win.

// Your task is to score the maximum points by shooting all the ballons wisely.

// Note: After you shoot bottle at i-th index, bottles at i-1 and i+1 positions
// become adjacent. if there is no existing 'i-1' or 'i+1' positions for selected bottle.
// you can assume that bottle[i-1] = bottle[i+1] = 1.

// Input Format:
// -------------
// N space separated integers bottles[].

// Output Format:
// --------------
// Print an integer, maximum points you can get.


// Sample Input:
// ---------------
// 3 1 5 8

// Sample Output:
// ----------------
// 167

// Explanation:
// ------------
// Given bottles = [3, 1, 5, 8] 
// position 	points
// --------------------
// 1				3*1*5
// 5				3*5*8
// 3				1*3*8
// 8				1*8*1
// --------------------
// Total = 167


// Sample Input:
// ---------------
// 2 1 3 5 4

// Sample Output:
// ----------------
// 102

// Explanation:
// ------------
// Given bottles = [2, 1, 3, 5, 4] 

// position 	points
// --------------------
// 5				3*5*4
// 1				2*1*3
// 3				2*3*4
// 2				1*2*4
// 4				1*4*1
// --------------------
// Total = 102



#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int maxi=INT_MIN;
	for(int k=i;k<=j;k++){
		int cost=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
		maxi=max(maxi,cost);
	}
	return dp[i][j]=maxi;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    string s;
    getline(cin,s);
    stringstream x1(s);
    string t1="";
    while(getline(x1,t1,' ')){
        nums.push_back(stoi(t1));
    }
    nums.push_back(1);
    int n=nums.size()-2;
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<f(1,n,nums,dp);
}
