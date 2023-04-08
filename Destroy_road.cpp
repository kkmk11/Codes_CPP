// Due to the heavy rains in TS & AP states, the road from 
// Hyderabad to Kakinada destroyed at N places.
// Let us assume Vijayawada is at the center bewteen Hyd and Kakinada
// NHAI planned to call for fresh bids to repair these pool of destroyed roads.

// The destroyed road is indicated as road[x]=[x-from, x-to], where 0 < = x < N 
// -500 <= x-from < x-to <= 500. The road from Hyderabad to Vijayawada indicated 
// with negative values, and Vijayawada to Kakinada indicated with positive values.

// A destroyed road D2 = [r, s] follows a destroyed road D1 = [p, q] if q < r.
// A pool of roads at different places can be formed in this way. 

// NHAI given a task to you to find the size of maximum pool can be formed.
// You do not need to use up all the given roads. You can select the roads in any order.

// Note: Size is the number of destroyed roads in the pool.

// Input Format:
// -------------
// Line-1: An integer N, number of roads.
// Next N lines: two space separated integers, x-from and x-to values.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 4
// 1 4
// -10 -3
// -5 0
// 5 6

// Sample Output-1:
// ----------------
// 3

// Explanation:
// ------------
// The pool is : [-10, -3] -> [1, 4] -> [5, 6]
// or [-5, 0] -> [1, 4] -> [5, 6]


// Sample Input-2:
// ---------------
// 4
// -50 -20
// -15 0
// 5 20
// 25 40

// Sample Output-2:
// ----------------
// 4

// Explanation:
// ------------
// The pool is : [-50, -20] -> [-15, 0] -> [5, 20] -> [25, 40]




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        nums.push_back({x,y});
    }
    sort(nums.begin(),nums.end(),[&](vector<int> a,vector<int> b){
       return a[1]<b[1]; 
    });
    int c=0,res=INT_MIN;
    for(auto v:nums){
        if(v[0]>res){
            res=v[1];
            c++;
        }
    }
    cout<<c;
}
