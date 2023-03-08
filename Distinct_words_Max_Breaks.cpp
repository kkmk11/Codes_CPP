// Mr Parandhamayya working with words.
// He is given a word W, you need to divide the word into N non-empty parts, 
// such that all the newly formed words should be distinct, and 
// if you append all those words should form original word W.

// Your task is to help Mr Parandhamayya to divide the word into N parts,
// such that, the value of N should be maximized, and print N.

// Input Format:
// -------------
// Line-1: A string W, a word.

// Output Format:
// --------------
// Print an integer result, the value of N.


// Sample Input-1:
// ---------------
// banana

// Sample Output-1:
// ----------------
// 4

// Explanation: 
// ------------
// One way to divide the word is "b","a","n","ana".
// If you divide it like "b","a","n","an","a".The word "a" will be repeated.
// So it is not allowed to divide like the second way.


// Sample Input-2:
// ---------------
// mississippi

// Sample Output-2:
// ----------------
// 7

// Explanation: 
// ------------
// One of the way to divide the word is "m","i","s","si","ssi","p","pi".

// NOTE: Subsequences are not allowed.





#include<bits/stdc++.h>
using namespace std;
int res=1;
void solve(string &s,vector<string> &v,set<string> &st,int ind){
    if(ind==s.size()){
        if(res<v.size()){
            res=v.size();
        }
        return;
    }
    string x="";
    for(int i=ind;i<s.size();i++){
        x=x+s[i];
        if(st.count(x)==0){
            v.push_back(x);
            st.insert(x);
            solve(s,v,st,i+1);
            st.erase(x);
            v.pop_back();
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<string> v;
    set<string> st;
    solve(s,v,st,0);
    cout<<res;
}
