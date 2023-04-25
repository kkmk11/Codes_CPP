// For Siddarth's Birthday his friends planned cake cutting.
// On top of the cake there are two lines of candles, 
// all the candles with different heights. 
// The lines are parallel lines, line-P and line-Q .
// Siddarth has to blow all the candles in one go.

// So, he can swap one candle at a time, from P and Q and 
// the position of the candles in their line should be same.

// At the end of the swaps, The candles in set P and set Q, 
// should be in ascending order of their heights.

// You will be heights of the candles initially in P and Q, after placing in parallel lines.

// Your task is to find the minimum number of swaps required
// to arrange the candles in P and Q in ascending orer.

// Note: It is guaranteed that the answer is always possible.

// Input Format:
// -------------
// Line-1: An integer N, num of candles in P and Q.
// Line-2: N space separated integers, heights of the candles in Line-P.
// Line-3: N space separated integers, heights of the candles in Line-Q.

// Output Format:
// --------------
// Print an integer, minimum number of swaps required.


// Sample Input-1:
// ---------------
// 4
// 1 3 5 4
// 1 2 3 7

// Sample Output-1:
// ----------------
// 1

// Explanation:
// ------------
// Swap the 4th candle in P and Q. 
// Then the heights of the candles in P = [1, 3, 5, 7],  Q = [1, 2, 3, 4]
// Both are in ascending order.


// Sample Input-2:
// ---------------
// 7
// 1 3 5 8 14 13 14
// 2 5 7 6 11 15 16

// Sample Output-2:
// ----------------
// 2

// Explanation:
// ------------
// Swap the 4th, 5th candles in P and Q. 
// Then the heights of the candles in 
// P = [1, 3, 5, 6, 11, 13, 14],  
// Q = [2, 5, 7, 8, 14, 15, 16]
// Both are in ascending order.




#include<bits/stdc++.h>
using namespace std;
int mini=INT_MAX;
void solve(vector<int> &a,vector<int> &b,int ind,int c){
    if(ind>=a.size()){
        mini=min(mini,c);
        return;
    }
    if(a[ind]>a[ind-1] && b[ind]>b[ind-1]){
        solve(a,b,ind+1,c);
    }
    if(a[ind]<a[ind-1] || b[ind]<b[ind-1] || (a[ind-1]<b[ind] && b[ind-1]<a[ind])){
        int a1=a[ind];
        int b1=b[ind];
        a[ind]=b1;
        b[ind]=a1;
        solve(a,b,ind+1,c+1);
        a[ind]=a1;
        b[ind]=b1;
    }
}
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
    solve(a,b,1,0);
    int a1=a[0];
    int b1=b[0];
    a[0]=b1;
    b[0]=a1;
    solve(a,b,1,1);
    cout<<mini;
}
