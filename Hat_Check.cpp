/*
Given a positive number n, find the total number of ways in which n hats can be returned to n people such that no hat makes it back to its owner.
input format: integer number n
output format : integer number m
Explanation :
Input:  2
Output:1
Explanation :The total number of derangements !2 is 1
 [h2, h1]
 
Input:  3
 Output:2
 Explanation :The total number of derangements !3 is 2
 
[h3, h1, h2]
[h2, h3, h1]
 
 
Input:  4
 
Output:9
Explanation :The total number of derangements !4 is 9
 
[h2, h1, h4, h3]
[h2, h3, h4, h1]
[h2, h4, h1, h3]
[h3, h4, h1, h2]
[h3, h1, h4, h2]
[h3, h4, h2, h1]
[h4, h1, h2, h3]
[h4, h3, h1, h2]
[h4, h3, h2, h1]

*/




#include<bits/stdc++.h>
using namespace std;
int c=0;
void solve(vector<int> &nums,int ind){
    if(ind==nums.size()){
        c++;
    }
    for(int i=ind;i<nums.size();i++){
        if(i!=nums[ind]){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        nums[i]=i;
    }
    solve(nums,0);
    cout<<c;
}
