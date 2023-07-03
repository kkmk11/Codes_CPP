// A chocolate vendor prepared a big chocolate of size M*N.
// This choloate is made using two kinds of chocolates, white and dark chocolate.
// Where white chocolate indiactes with '0' and Dark Chocolate is with '1'.

// You will be given the big chocolate of size M*N.
// Your task is to find out, number of dark chacolates can be formed
// with rectangular shapes from the grid.

// NOTE: You can assume that all the 1*1 chocolate have same size.

// Input Format:
// -------------
// Line-1: Two space seprated integers, M and N size of chocolate.
// Next M lines: N space seprated integers, only 0's and 1's.

// Output Format:
// --------------
// Print an integer value.


// Sample Input-1:
// ---------------
// 2 3
// 1 1 0
// 0 1 1

// Sample Output-1:
// ----------------
// 7

// Explanation:
// ------------
// There are 4 dark-chocolates of size 1x1.
// There are 2 dark-chocolates of size 1x2.
// There are 1 dark-chocolates of size 2x1.


// Sample Input-2:
// ---------------
// 3 4
// 1 0 1 1
// 1 1 0 1
// 1 1 1 0

// Sample Output-2:
// ----------------
// 20

// Explanation:
// ------------
// There are 9 dark-chocolates of size 1x1
// There are 4 dark-chocolates of size 1x2
// There is 1 dark-chocolate of size 1x3
// There are 4 dark-chocolate of size 2x1
// There is 1 dark-chocolate of size 3x1
// There is 1 dark-chocolate of size 2x2




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nums(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=i;k<n;k++){
                for(int l=j;l<m;l++){
                    int flag=0;
                    for(int x=i;x<=k;x++){
                        for(int y=j;y<=l;y++){
                            if(nums[x][y]!=1){
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1){
                            break;
                        }
                    }
                    if(flag==0){
                        c++;
                    }
                }
            }
        }
    }
    cout<<c;
}
