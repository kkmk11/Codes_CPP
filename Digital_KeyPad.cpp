// Given a classic mobile phone, and the key pad of the phone looks like below.
// 	1		2		3
// 		   abc	   def
		 
// 	4		5		6
//    ghi     jkl     mno
  
// 	7		8		9
//   pqrs     tuv    wxyz
	
// 	*		0		#


// You are given a string S contains digits between [2-9] only, 
// For example: S = "2", then the possible words are "a", "b", "c".

// Now your task is to find all possible words that the string S could represent.
// and print them in a lexicographical order. 

// Input Format:
// -------------
// A string S, consist of digits [2-9]

// Output Format:
// --------------
// Print the list of words in lexicographical order.


// Sample Input-1:
// ---------------
// 2

// Sample Output-1:
// ----------------
// [a, b, c]


// Sample Input-2:
// ---------------
// 24

// Sample Output-2:
// ----------------
// [ag, ah, ai, bg, bh, bi, cg, ch, ci]




#include<bits/stdc++.h>
using namespace std;

vector<string> res;
unordered_map<char,string> m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
void solve(string &digits,string &x,int ind){
    if(ind==digits.size()){
        res.push_back(x);
        return;
    }
    string s=m[digits[ind]];
    for(int i=0;i<s.size();i++){
        x=x+s[i];
        solve(digits,x,ind+1);
        x.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    string s=to_string(n);
    string x="";
    solve(s,x,0);
    for(auto i:res){
        cout<<i<<" ";
    }
}
