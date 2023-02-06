// Given an array of integer elements, ele[], YOur task is to find and print 
// the number of the subarrays, which gives you an even value after multiplication
// of the elements in it.

// Input Format:
// -------------
// Line-1: An integer N, number of elements.
// Line-2: Space separated elements.

// Output Format:
// --------------
// Print number of possible subarrays.


// Sample Input-1:
// ---------------
// 4
// 5 8 9 17

// Sample Output-1:
// ----------------
// 6

// Explanation:
// ------------
// 5 x 8 = 40
// 5 x 8 x 9 = 360
// 5 x 8 x 9 x 17 = 6120
// 8 = 8
// 8 x 9 = 72
// 8 x 9 x 17 = 1224
// Hence we got 6 even subarray multiplications.



// Sample Input-2:
// ---------------
// 3
// 5 7 11

// Sample Output-2:
// ----------------
// 0

// Explanation:
// ------------
// No subarrays which will give you even value after multiplication.



//SUBARRAYS PROBLEM TEMPLATE:
// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> res;
// void solve(vector<int> &nums,int start,int end){
//     if(end==nums.size()){
//         return;
//     }
//     else if(start>end){
//         solve(nums,0,end+1);
//     }
//     else{
//         vector<int> v;
//         for(int i=start;i<end;i++){
//             v.push_back(nums[i]);
//         }
//         v.push_back(nums[end]);
//         res.push_back(v);
        
//         solve(nums,start+1,end);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n,0);
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     solve(nums,0,0);
//     for(auto v:res){
//         for(int i:v){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
// }


Solution:
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
int c=0;
void solve(vector<int> &nums,int start,int end){
    if(end==nums.size()){
        return;
    }
    else if(start>end){
        solve(nums,0,end+1);
    }
    else{
        int res=1;
        for(int i=start;i<end;i++){
            res*=(nums[i]);
        }
        res*=nums[end];
        if(res%2==0){
            c++;
        }
        solve(nums,start+1,end);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solve(nums,0,0);
    cout<<c;
}
