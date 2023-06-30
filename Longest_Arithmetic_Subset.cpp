// Ismart Shankar is given a set of N pluck cards, each card labelled 
// with a number on it, and he is also given a difference value as ‘D’.
// Now Ismart Shankar has to find out the length of the largest arithmetic set ‘S’.

// A subset is called as arithmetic set, iff the difference between 
// the numbers on any two adjacent cards is same as D.

// A subset can be derived from the set of N pluck cads by deleting
// some or no cards without changing the order of the remaining cards.

// Input Format:
// ------------- 
// Line-1: Two space separated integers N, D, number of cards, difference.
// Line-2: N space separated integers, numbers on the set of cards.

// Output Format:
// --------------
// Print an integer, length of longest arithmetic subset.


// Sample Input-1:
// ---------------
// 6 2
// 1 2 3 4 6 8

// Sample Output-1:
// ----------------
// 4

// Sample Input-2:
// ---------------
// 8 -2
// 8 1 2 6 5 4 2 0 

// Sample Output-2:
// ----------------
// 5




#include<bits/stdc++.h>
using namespace std;
int maxi=1;
// void solve(vector<int> &nums,int ind,int d,int c){
//     if(ind==nums.size()){
//         maxi=max(maxi,c);
//         return;
//     }
//     for(int i=ind+1;i<nums.size();i++){
//         if(nums[i]-nums[ind]==d){
//             solve(nums,i,d,c+1);
//         }
//     }
//     solve(nums,ind+1,d,c);
// }    //during Recursion, 1 test case is failing...should find it out... 
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // solve(nums,0,d,1);
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(nums[i]-nums[j]==d){
                dp[i]=max(dp[i],1+dp[j]);
                maxi=max(maxi,dp[i]);
            }
        }
    }
    cout<<maxi;
}
