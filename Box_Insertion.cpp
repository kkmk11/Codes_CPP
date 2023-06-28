/*Mr.Balu is working in a metal store he has to arrange the steel boxes for saving space he used to insert one box into another,Every day he used to get different sized boxes, help him to make his work simple by writing a program to find maximum number of boxes he can put one inside the other. For this, You are given a 2D array of integers boxes where boxes[i] = [wi, hi] represents the width and the height of a box.
One box can fit into another if and only if both the width and height of one box are greater than the other box's width and height.
Return the maximum number of boxes you can  put one inside the other.
Note: Consider only width and height of boxes.

Example 1:
Input: boxes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of boxes you can insert is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: 3
1 1 
1 1
1 1
Output: 1
*/




#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> &v,vector<int> &dp,int ind){
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int maxi=1;
    for(int i=ind+1;i<v.size();i++){
        if(v[ind][0]<v[i][0] && v[ind][1]<v[i][1]){
            int x=1+solve(v,dp,i);
            maxi=max(maxi,x);
        }
    }
    dp[ind]=maxi;
    return dp[ind];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (2,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>v[i][j];
        }
    }
    sort(v.begin(),v.end(),[&](vector<int> a,vector<int> b){
       if(a[0]<b[0]){
           return true;
       } 
       else if(a[0]==b[0]){
           if(a[1]<b[1]){
               return true;
           }
           else{
               return false;
           }
       }
       else{
           return false;
       }
    });
    int maxi=INT_MIN;
    vector<int> dp(v.size(),-1);
    for(int i=0;i<v.size();i++){
        int x=solve(v,dp,i);
        maxi=max(maxi,x);
    }
    cout<<maxi;
}
