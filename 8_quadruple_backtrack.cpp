// In a Mathematics class students are given a list  which are  distinct  and 
// positive integers. Students should do the calculation and return 
// the number of quadraples (p, q, r, s) such that p * q = r * s
// where p, q, r, and s are elements of list, and p != q != r != s.

// Input Format
// -------------
// Line-1: An integer N, number of elements in the list
// Line-2: N space separated integers, the list[]

// Output Format
// -------------
// An integer which is no of quadraples


// Sample Input-1:
// ---------------
// 4
// 2 3 4 6

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------
// There are 8 valid quadraples:
// (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
// (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)


// Sample Input:
// -------------
// 5
// 1 2 4 8 16

// Sample Output:
// --------------
// 24

// Explanation:
// ------------
// There are 24 valid quadraples:
// (1,16,2,8) , (1,16,8,2) , (16,1,2,8) , (16,1,8,2)
// (2,8,1,16) , (2,8,16,1) , (8,2,1,16) , (8,2,16,1)
// (1,8,4,2) , (1,8,2,4) , (8,1,4,2) , (8,1,2,4)
// (4,2,1,8) , (4,2,8,1) , (2,4,1,8) , (2,4,8,1)
// (2,16,4,8) , (2,16,8,4) , (16,2,4,8) , (16,2,8,4)
// (4,8,2,16) , (4,8,16,2) , (8,4,2,16) , (8,4,16,2)


solution1:
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void solve(vector<int> &nums,vector<int> &v,int ind){
    if(ind==4){
        res.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[i],nums[ind]);
        solve(nums,v,ind+1);
        swap(nums[i],nums[ind]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> x;
    solve(nums,x,0);
    int c=0;
    for(auto v:res){
        if(v[0]*v[1]==v[2]*v[3]){
            c++;
        }
    }
    cout<<c;
}



solution2:
#include<bits/stdc++.h>
using namespace std;
int c=0;
void solve(vector<int> &nums,int ind){
    if(ind==4){
        if(nums[0]*nums[1]==nums[2]*nums[3]){
            c++;
        }
        return;
    }q  
    for(int i=ind;i<nums.size();i++){
        swap(nums[i],nums[ind]);
        solve(nums,ind+1);
        swap(nums[i],nums[ind]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solve(nums,0);
    cout<<c;
}
