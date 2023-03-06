// There are some cubes, each cube is printed with an alphabet [A-Z].
// Using these cubes, you can create non-empty distinct words.
// and length of the words should be 0< length <= no.of.cubes.

// You are given a string of alphabets S, 
// Your task is to findout number of possible non-empty distinct words

// Input Format:
// -------------
// A string S, consist of A-Z letters only.

// Output Format:
// --------------
// Print an integer, number of possible non-empty distinct words.


// Sample Input-1:
// ---------------
// EGG

// Sample Output-1:
// ----------------
// 8

// Explanation:
// --------------
// The possible distinct words are "E", "G", "EG", "GG", "GE", "EGG", "GEG", "GGE".


// Sample Input-2:
// ---------------
// MADAM

// Sample Output-2:
// ----------------
// 89





#include<bits/stdc++.h>
using namespace std;

unordered_set<string> res;
void helper(string &s,int ind){
    if(ind==s.size()){
        res.insert(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        helper(s,ind+1);
        swap(s[i],s[ind]);
    }
}
void solve(string &s,int ind,string &x){
    helper(x,0);
    for(int i=ind;i<s.size();i++){
        x=x+s[i];
        solve(s,i+1,x);
        x.pop_back();
    }
}
int main(){
    string s,x="";
    cin>>s;
    solve(s,0,x);
    cout<<res.size()-1;
}
