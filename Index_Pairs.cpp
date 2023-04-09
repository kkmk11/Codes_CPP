// An 8th standard student has been assigned a task as part of punishment for his mistake.

// The task is, there is an input string STR(without any space) and an array of 
// strings words[]. Print all the pairs of indices [s, e] where s, e are starting 
// index and ending index of every string in words[] in the input string STR.

// Note: Print the pairs[s, e] in sorted order.
// (i.e., sort them by their first coordinate, and in case of ties sort them by 
// their second coordinate).

// Input Format
// ------------
// Line-1: string STR(without any space)
// Line-2: space separated strings, words[]

// Output Format
// -------------
// Print the pairs[s, e] in sorted order.


// Sample Input-1:
// ---------------
// thekmecandngitcolleges
// colleges kmec ngit

// Sample Output-1:
// ----------------
// 3 6
// 10 13
// 14 21


// Sample Input-2:
// ---------------
// xyxyx
// xyx xy

// Sample Output-2:
// ----------------
// 0 1
// 0 2
// 2 3
// 2 4

// Explanation: 
// ------------
// Notice that matches can overlap, see "xyx" is found at [0,2] and [2,4].


// Sample Input-3:
// ---------------
// kmecngitkmitarecsecolleges
// kmit ngit kmec cse

// Sample Output-3:
// ----------------
// 0 3
// 4 7
// 8 11
// 15 17



#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> v;
    string s1;
    cin>>s1;
    cin.ignore();
    string s;
    getline(cin,s);
    stringstream x1(s);
    string t1;
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    vector<vector<int>> res;
    for(auto a:v){
        for(int i=0;i<s1.size()-a.size()+1;i++){
            if(a==s1.substr(i,a.size())){
                res.push_back({i,i+a.size()-1});
            }
        }
    }
    sort(res.begin(),res.end(),[&](vector<int> a,vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            if(a[1]<b[1]){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    });
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
