// Kiran is playing with strings and its subsequences.
// A subsequence can be formed from a string by deleting some characters
// (may be string itself)

// Kiran has given two strings S and T, your task to form T by concatenating 
// the subsequences of S  

// Return the minimum number of subsequences required to form T.
// If the task is impossible, return -1 .


// Input Format:
// -------------
// Line-1 -> Two strings S and T

// Output Format:
// --------------
// Print an integer as result.


// Sample Input-1:
// ---------------
// abc abcbc

// Sample Output-1:
// ----------------
// 2

// Explanation: 
// ------------
// T = "abcbc" can be formed by "abc" and "bc",
// which are subsequences of S = "abc".


// Sample Input-2:
// ---------------
// abc acdbc

// Sample Output-2:
// ----------------
// -1

// Explanation: 
// ------------
// string T cannot be constructed from the
// subsequences of string S due to the character "d" in string T.





#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string s){
    vector<vector<int>> dp(x.size()+1,vector<int> (s.size()+1,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(x[i-1]==s[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[x.size()][s.size()];
}
int main(){
    string a,s;
    cin>>a>>s;
    string x="";
    int flag=0;
    int c=0;
    while(x.size()<10000){
        if(lcs(x,s)==s.size()){
            flag=1;
            break;
        }
        else{
            c++;
            x=x+a;
        }
    }
    if(flag==0){
        cout<<-1;
    }
    else{
        cout<<c;
    }
}
