// Nehanth, a bubbly kid playing with digits and creating numbers using them.
// The kid is creating the number called successive number. 
// A number is called successive number, if and only if 
// each digit in the number is one less than the next digit.

// You are given two integers, start and end, both are inclusive.
// Your task to find and print all the successive numbers in the given range (start, end).

// Input Format:
// -------------
// Two space separated integers, start and end

// Output Format:
// --------------
// Print the list of successive numbers in the range(start, end).


// Sample Input-1:
// ---------------
// 50 150

// Sample Output-1:
// ----------------
// [56, 67, 78, 89, 123]


// Sample Input-2:
// ---------------
// 100 600

// Sample Output-2:
// ----------------
// [123, 234, 345, 456, 567]





#include<bits/stdc++.h>
using namespace std;
set<int> st;
void solve(string &x,string &p,int s,int e){
    if(p.size()>0 && stoi(p)>=s && stoi(p)<=e){
        st.insert(stoi(p));
    }
    for(int i=0;i<x.size();i++){
        if(p.size()==0 || ((x[i]-'0')-(p.back()-'0')==1)){
            p=p+x[i];
            solve(x,p,s,e);
            p.pop_back();
        }
    }
}
int main(){
    int s,e;
    cin>>s>>e;
    string x="0123456789";
    string p="";
    solve(x,p,s,e);
    for(int i:st){
        cout<<i<<" ";
    }
}

