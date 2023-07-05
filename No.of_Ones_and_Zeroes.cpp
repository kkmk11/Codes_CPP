// Mounika is creating the binary strings using P 1's and Q 0's.
// A binary string contains only 0's and 1's.
// She has given a list of binary strings binStr[] to be formed.

// Her task is to find, the maximum number of binary strings can be formed, 
// with given P no.of 1's and Q no.of 0's only. She cannot use any more 1's or 0's.

// Input Format:
// -------------
// Line-1 -> A single line of space separated binary strings, binStr[].
// Line-2 -> Two integers P and Q, P number of 1's and Q number of 0's


// Output Format:
// --------------
// Print an integer as output, maximum number of binary strings can be formed.


// Sample Input-1:
// ---------------
// 10 0001 111001 1 0
// 3 5

// Sample Output-1:
// ----------------
// 4

// Explanation:
// ------------
// She can form 4 strings by the using of 3 1's and 5 0's
// strings are 10, 0001, 1, 0.


// Sample Input-2:
// ---------------
// 10 1 0
// 1 1

// Sample Output-2:
// ----------------
// 2

// Explanation:
// ------------
// She can form 2 strings by the using of 1 1's and 1 0's
// strings are 1, 0.




#include<bits/stdc++.h>
using namespace std;
int solve(vector<string> &v,int zero,int one,int ind,vector<vector<vector<int>>> &dp){
    if(ind==v.size() || (zero==0 && one==0)){
        return 0;
    }
    if(dp[zero][one][ind]>0){
        return dp[zero][one][ind];
    }
    string s=v[ind];
    unordered_map<char,int> m;
    for(char i:s){
        m[i]++;
    }
    int a=0;
    if(zero>=m['0'] && one>=m['1']){
        a=1+solve(v,zero-m['0'],one-m['1'],ind+1,dp);
    }
    int b=solve(v,zero,one,ind+1,dp);
    
    dp[zero][one][ind]=max(a,b);
    return dp[zero][one][ind];
}
int main(){
    string s1;
    getline(cin,s1);
    stringstream x1(s1);
    vector<string> v;
    string t1="";
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    int one,zero;
    cin>>one>>zero;
    vector<vector<vector<int>>> dp(zero+1,vector<vector<int>> (one+1,vector<int> (v.size(),0)));
    cout<<solve(v,zero,one,0,dp);
}
