// In a maths class, Teahcer given a task to a student.
// Initially, Teacher provided a set of tokens(one on another) to the student
// All the tokens are printed a positive number on one side and empty on other side
// Intially, the number side of tokens are hidden.

// Now, you do the following steps repeatedly, until all tokens are turned up:
//     1. Take the top token of the set, show the number, and take it out of the set.
//     2. If there are still tokens in the set, put the next top token of the set 
//        at the bottom of the set.
//     3. If there are still hidden tokens, go back to step 1. Otherwise, stop.

// Your task is to help students to find and return an ordering of the set, that 
// would show the tokens in increasing order. 

// NOTE: The first entry in the answer is considered to be the top of the set.

// Input Format:
// -------------
// Line-1 -> An integer N, no of tokens
// Line-2 -> N space separated integers.

// Output Format:
// --------------
// Print N space separated integers as result.


// Sample Input-1:
// ---------------
// 7
// 7 6 5 1 2 3 4

// Sample Output-1:
// ----------------
// 1 6 2 5 3 7 4

// Explanation: 
// ---------------
// Given a set in the order 7 6 5 1 2 3 4
// After reordering, the set starts as 1 6 2 5 3 7 4, where 1 is the top of the set.
// Student show 1, and move 6 to the bottom.  The set is now 2 5 3 7 4 6.
// Student show 2, and move 5 to the bottom.  The set is now 3 7 4 6 5.
// Student show 3, and move 7 to the bottom.  The set is now 4 6 5 7
// Student show 4, and move 6 to the bottom.  The set is now 5 7 6
// Student show 5. and move 7 to the bottom.  The set is now 6 7
// Student show 6, and move 7 to the bottom.  The set is now 7
// Student show 7.
// Since all the cards revealed are in increasing order, the answer is correct.




#include<bits/stdc++.h>
using namespace std;
int main(){
    int mini=INT_MAX;
    int n,x=0;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    vector<int> res(n,0);
    for(int i=0;i<n;i++){
        int x=q.front();
        q.pop();
        res[x]=v[i];
        int front=q.front();
        q.pop();
        q.push(front);
    }
    for(int i:res){
        cout<<i<<" ";
    }
}
