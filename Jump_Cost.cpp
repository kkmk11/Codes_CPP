// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi
// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
// If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣h i −h j ∣ is incurred, where 
// j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.
// Constraints
// All values in input are integers.
// 2≤N≤10 ^5
//  1≤h i≤10 ^4
 
// Input
// Input is given from Standard Input in the following format:

// N
// h 1 h 2… h N
// ​
// Output
// Print the minimum possible total cost incurred.
// Sample Input 1
// 4
// 10 30 40 20
// Ouput
// 30

// If we follow the path 1 → 2 → 4, the total cost incurred would be 
// ∣10−30∣+∣30−20∣=30.

// Sample Input 2
// 2
// 10 10
// Sample Output2
// 0
// If we follow the path 
// 1 → 2, the total cost incurred would be ∣10−10∣=0.

// Sample Input 3
// 6
// 30 10 60 10 60 50
// Sample Output
// 40
// If we follow the path 
// 1 → 3 → 5 → 6, the total cost incurred would be ∣30−60∣+∣60−60∣+∣60−50∣=40. 




#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100000,-1);
int solve(vector<int> &v,int i,int n){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int cost=abs(v[i]-v[i+1])+solve(v,i+1,n);
    if(i+2<=n){
        cost=min(cost,abs(v[i]-v[i+2])+solve(v,i+2,n));
    }
    dp[i]=cost;
    return dp[i];
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v,0,n-1);
}
