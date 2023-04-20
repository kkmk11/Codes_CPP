// A merchant has two types of idols, gold and silver.
// He has arranged the idols in the form of m*n grid, 
// 	- the gold idols are represented as 1's 
// 	- the silver idols are represented as 0's.

// Your task is to find the longest consecutive arrangement of gold idols, 
// The arrangement can be either horizontal, vertical, diagonal or 
// antidiagonal, but not the combination of these.


// Input Format:
// -------------
// Line-1: Two space separated integers m and n, grid size.
// Next m lines : n space separated integers, arrangement of idols.

// Output Format:
// --------------
// Print an integer, longest arranement of gold idols.


// Sample Input:
// ---------------
// 4 5
// 1 0 1 1 1
// 0 1 0 1 0
// 1 0 1 0 1
// 1 1 0 1 1

// Sample Output:
// ----------------
// 4



Solution 1: 
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void horizontal(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    horizontal(nums,i+1,j,sum);
    v.push_back(sum);
}
void vertical(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    vertical(nums,i,j+1,sum);
    v.push_back(sum);
}
void diagonal_right(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    diagonal_right(nums,i+1,j+1,sum);
    v.push_back(sum);
}
void diagonal_left(vector<vector<int>> &nums,int i,int j,int &sum){
    if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==0){
        return;
    }
    sum++;
    diagonal_left(nums,i-1,j+1,sum);
    v.push_back(sum);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                int a=0,b=0,c=0,d=0;
                horizontal(grid,i,j,a);
                vertical(grid,i,j,b);
                diagonal_right(grid,i,j,c);
                diagonal_left(grid,i,j,d);
                int x=*max_element(v.begin(),v.end());
                maxi=max(maxi,x);
                v.clear();
            }
        }
    }
    cout<<maxi;
}



solution 2:
import java.util.*;
class j{
    static int ans=0;
    static int hor(int i,int j,int n,int m,int[][] a){
        if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0){
            return 0;
        }
        return 1+hor(i,j+1,n,m,a);
    }
    static int ver(int i,int j,int n,int m,int[][] a){
        if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0){
            return 0;
        }
        return 1+ver(i+1,j,n,m,a);
    }
    static int dia(int i,int j,int n,int m,int[][] a){
        if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0){
            return 0;
        }
        return 1+dia(i+1,j+1,n,m,a);
    }
    static int anti(int i,int j,int n,int m,int[][] a){
        if(i<0 || j<0 || i>=n || j>=m || a[i][j]==0){
            return 0;
        }
        return 1+anti(i-1,j+1,n,m,a);
    }
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] a=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    ans=Math.max(ans,hor(i,j,n,m,a));
                    ans=Math.max(ans,ver(i,j,n,m,a));
                    ans=Math.max(ans,dia(i,j,n,m,a));
                    ans=Math.max(ans,anti(i,j,n,m,a));
                }
            }
        }
        System.out.println(ans);
    }
}
