// You are given a phrase and a paper of size m*n.
// So you can type exactly m * n characters on that paper.
// i.e,. there are 'm' rows and in each row you can type 'n' characters
// You need to type the phrase on the paper with some rules.

// The rules are as follows:
//     - A word in the phrase cannot be split into two lines.
//     - The order of words in the phrase shuld not change.
//     - Two consecutive words in a line must be separated by a single space.

// Your task is to find out how many times the phrase can be typed on the paper.


// Constraint:
// -----------
// Length of each word is <=10.

// Input Format:
// -------------
// Line-1: Three space separated integers m, n, and s, grid size m*n, number of words.
// Line-2: 's' space separated strings, set of words

// Output Format:
// --------------
// Print an integer, no.of times set of words fit into the grid.


// Sample Input-1:
// ---------------
// 2 8 2
// socail distance

// Sample Output-1:
// ----------------
// 1

// Explanation:
// ------------
// social__
// distance


// Sample Input-2:
// ---------------
// 3 6 3
// a bc def

// Sample Output-2:
// ----------------
// 2

// Explanation:
// ------------
// a_bc__
// def_a_
// bc_def



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,w;
    cin>>n>>m>>w;
    string s,t1;
    cin.ignore();
    getline(cin,s);
    vector<string> v;
    stringstream x1(s);
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    int count=0,i=0,k=0,x=0;
    while(i<n){
        if(v[k].size()+x<=m){
            x=x+v[k].size()+1;
            k++;
        }
        else{
            i++;
            x=0;
        }
        if(k==v.size()){
            count++;
            k=0;
        }
    }
    cout<<count;
}
