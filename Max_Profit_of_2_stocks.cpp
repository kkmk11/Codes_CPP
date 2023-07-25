// Given a list containing future price predictions of two different stocks for the next n days, find the maximum profit earned by selling the stocks with a constraint that the second stock can be sold, only if no transaction happened on the previous day for any of the stock.

// Assume that the given prices are relative to the buying price. Each day, we can either sell a single share of the first stock or a single share of the second stock or sell nothing.
// input format:an integer m
//              m number of integers for x
// 			 m number of integers for y
// output format : integer
// example
// sample case 1:
// 5
// 5 3 4 6 3
// 8 4 3 5 10
// output = 25
// explanation:
// Day 1: Sell stock y at a price of 8
// Day 2: Sell stock x at a price of 3
// Day 3: Sell stock x at a price of 4
// Day 4: Do not sell anything
// Day 5: Sell stock y at a price of 10



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=max(a[0],b[0]);
    for(int i=2;i<dp.size();i++){
        dp[i]=max(a[i-1]+dp[i-1],b[i-1]+dp[i-2]);
    }
    cout<<dp[n];
}
