// Given a matrix of dimension rows X cols with the elements 0's and 1's,

// Your task is to convert all matrix elements to 0's by following 
// the condition given below.

// The condition is, in every operation, you could select any 
// row or any column of the given matrix and toggle each element 
// in that row or column.

// Note: Toggle means changing all 0's to 1's and all 1's to 0's.

// Print true if you could change all matirix elements to 0's 
// by following given condition else print false.


// Input Format
// -------------
// Line-1: Read two integers rows and cols(space separated).
// Line-2: Read the matrix of dimension rows X cols.

// Output Format
// --------------
// Print a boolean result.



// Sample input-1:
// ---------------
// 5 5
// 0 0 1 0 0
// 0 0 1 0 0
// 1 1 0 1 1
// 0 0 1 0 0
// 0 0 1 0 0

// Sample output-1:
// ----------------
// true

// Explanation:
// ------------
// 0 0 1 0 0          0 0 1 0 0           0 0 0 0 0
// 0 0 1 0 0   row-3  0 0 1 0 0   cols-3  0 0 0 0 0
// 1 1 0 1 1   --->   0 0 1 0 0   --->    0 0 0 0 0
// 0 0 1 0 0          0 0 1 0 0           0 0 0 0 0
// 0 0 1 0 0          0 0 1 0 0           0 0 0 0 0 


// Sample input-2
// --------------
// 2 2
// 1 1
// 0 1

// Sample output-2
// ---------------
// false


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,sum=0;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<n;i++){
        unordered_set<int> s;
        for(int j=0;j<m;j++){
            s.insert(mat[0][j]^mat[i][j]);
        }
        if(s.size()>1){
            cout<<"false";
            exit(0);
        }
    }
    cout<<"true";
}
