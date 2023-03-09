//     There are some Special Numbers between 0 to 10^N.
// A number is called special, if all the digits in that number should be different.
// i.e., No two digits are same in that number.

// You are given an integer N,
// Your task is to find the count of special numbers (X) between 0<= X < 10^N.

// NOTE: Leading 0's are allowed.

// Input Format:
// -------------
// An integer N

// Output Format:
// --------------
// Print an integer, Count of special numbers.

// Sample Input-1:
// ---------------
// 1

// Sample Output-1:
// ----------------
// 10


// Sample Input-1:
// ---------------
// 2

// Sample Output-1:
// ----------------
// 91

// Explanation:
// --------------
// Special Number between 0<= X < 10^2.
// Exclude 11, 22, 33, 44, 55, 66, 77, 88, 99, => count is 9
// Total Count is 100=> Special Numbers count is 100-9 = 91.




#include<bits/stdc++.h>
using namespace std;
int c=0;
void solve(string &s,int n,string &x){
    if(x.size()==n){
        return;
    }
    for(int i=0;i<s.size();i++){
        if(x.size()==0 || (x.find(s[i])==-1 && x[0]!='0')){
            x=x+s[i];
            c++;
            solve(s,n,x);
            x.pop_back();
        }
    }
}
int main(){
    int n;
    cin>>n;
    string s="0123456789";
    string x="";
    solve(s,n,x);
    cout<<c;
}
