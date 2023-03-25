// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 
// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.



#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  int m=a.size()+1;
  int n=b.size()+1;
  vector<vector<int>> dp(m,vector<int> (n,0));
  for(int i=0;i<m;i++){
      dp[i][0]=i;
  }
  for(int i=0;i<n;i++){
      dp[0][i]=i;
  }
  for(int i=1;i<m;i++){
      for(int j=1;j<n;j++){
          if(a[i-1]==b[j-1]){
              dp[i][j]=dp[i-1][j-1];
          }
          else{
              dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
          }
      }
  }
  cout<<dp[m-1][n-1];
}
