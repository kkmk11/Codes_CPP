// In a school, the students are given an array of strings words[]. Students have 
// to find the longest string in words[] such that every prefix of it is also in words.

// For example, let words = ["a", "app", "ap","appl", "apply"]. The string "apply" 
// has prefixes "ap","app","appl" and "a", all of which are in words.

// Your task is the find and return the longest string in words as described above.

// If there is more than one string with the same length, return the lexicographically
// smallest one, and if no string exists, return "".

// Input Format
// -------------
// Line1: string separated by spaces
 
// Output Format
// --------------
// string 

// Sample Input-1:
// ---------------
// k kmi km kmit

// Sample Output-1:
// ----------------
// kmit

// Explanation:
// ------------
// "kmit" has prefixes "kmi", "km", "k" and all of them appear in words.


// Sample Input-2:
// ---------------
// t tanker tup tupl tu tuple tupla

// Sample Output-2:
// ----------------
// tupla

// Explanation:
// ------------
// Both "tuple" and "tupla" have all their prefixes in words.
// However, "tupla" is lexicographically smaller, so we return that.


// Sample Input-3:
// ---------------
// abc bc ab abcd

// Sample Output-3:
// ----------------
// ""




#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> v;
    string s1,t1;
    getline(cin,s1);
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    unordered_map<int,set<string>> m;
    int maxi=INT_MIN;
    for(auto s:v){
        int c=0;
        for(auto a:v){
            if(s.find(a)==0){
                c++;
            }
        }
        c--;
        m[c].insert(s);
        maxi=max(maxi,c);
    }
    for(auto i:m[maxi]){
        cout<<i;
        exit(0);
    }
}
