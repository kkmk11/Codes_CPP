// Clavius, the person who suggested grouping of data using brackets.
// He has suggested that the group of brackets should be Well-Formed.

// A string is said to be Well-Formed, if:
//     - The string is empty.
//     - The string can be written as MN, (M is appended to N), 
//       where M and N are Well-Formed Strings, or
//     - The string can be written as {M}, where M is Well-Formed string.

// You will be given an integer N. Your task is to return the list of all 
// Well-Formed strings of length 2*N.

// Input Format:
// -------------
// An integer N.

// Output Format:
// --------------
// Print the list of well-formed strings.


// Sample Input-1:
// ---------------
// 3

// Sample Output-1:
// ----------------
// [{{{}}},{{}{}},{{}}{},{}{{}},{}{}{}]


// Sample Input-2:
// ---------------
// 1

// Sample Output-2:
// ----------------
// [{}]




#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void solve(int n,string x,int open,int close){
    if(x.size()==2*n){
        res.push_back(x);
        return;
    }
    if(open<n){
        x=x+"{";
        solve(n,x,open+1,close);
        x.pop_back();
    }
    if(close<open){
        x=x+"}";
        solve(n,x,open,close+1);
        x.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string x="";
    solve(n,x,0,0);
    for(auto i:res){
        cout<<i<<" ";
    }
}
