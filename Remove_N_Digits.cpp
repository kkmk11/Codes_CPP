// Somesh is working on Number Strings.
// He got an idea to find the smallest possible number by 
// deleting some digits from the number without changing 
// the relative order of digits in it.

// You will be given a integer String 'num', and an integer n.
// Find the smallest number possible after deleting n digits from 'num'.

// Note: If the number string 'num' turns to empty, print 0.

// Input Format:
// -------------
// Line-1 : A string num, consist of digits only.
// Line-2 : An integer n, number of digits to delete.

// Output Format:
// --------------
// Print the smallest possible number.


// Sample Input-1:
// ---------------
// 1432219
// 3

// Sample Output-1:
// ----------------
// 1219

// Explanation: 
// ------------
// Delete the three digits 4, 3, and 2 to form the smallest number 1219.


// Sample Input-2:
// ---------------
// 10200
// 1

// Sample Output-2:
// ----------------
// 200

// Explanation:
// ------------
// Delete the leading 1 and the smallest number is 200. 
// Note that the output must not contain leading zeroes.





#include<bits/stdc++.h>
using namespace std;
long long mini=1e14;
void solve(string &s,string  &x,int k,int ind){
    if(x.size()==s.size()-k){
        if(x[0]=='0'){
            string p=x.substr(1);
            if(p.size()==0){
                mini=0;
            }
            else{
                mini=min(mini,stoll(p));
            }
        }
        else{
            mini=min(mini,stoll(x));
        }
        return;
    }
    for(int i=ind;i<s.size();i++){
        x=x+s[i];
        solve(s,x,k,i+1);
        x.pop_back();
    }
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    if(k>=s.size()){
        cout<<0;
        exit(0);
    }
    string x="";
    solve(s,x,k,0);
    cout<<mini;
}
