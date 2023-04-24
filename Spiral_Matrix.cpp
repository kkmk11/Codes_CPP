// You will be given the matrix of size R*C,

// You have to return the matrix in special order as shown in the sample tescases.
 

// Input Format:
// -------------
// Line-1 -> Two integers R and C, size of matrix.
// Next R-Lines -> C space separated integers

// Output Format:
// --------------
// Print R-Lines -> C space separated integers, in special order.


// Sample Input-1:
// ---------------
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Sample Output-1:
// ----------------
// 1 2 3
// 6 9 8
// 7 4 5


// Sample Input-2:
// ---------------
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12

// Sample Output-2:
// ----------------
// 1 2 3 4
// 8 12 11 10
// 9 5 6 7




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int rb=0,re=n-1;
    int cb=0,ce=m-1;
    vector<int> res;
    while(rb<=re && cb<=ce){
        for(int i=cb;i<=ce;i++){
            res.push_back(v[rb][i]);
        }
        rb++;
        for(int j=rb;j<=re;j++){
            res.push_back(v[j][ce]);
        }
        ce--;
        for(int i=ce;i>=cb && rb<=re;i--){
            res.push_back(v[re][i]);
        }
        re--;
        for(int j=re;j>=rb && cb<=ce;j--){
            res.push_back(v[j][cb]);
        }
        cb++;
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[k]<<" ";
            k++;
        }
        cout<<endl;
    }
}
