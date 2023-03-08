// You are given a set of N integers, and a value to find F. Initially a variable, 
// 'total' is set to 0. You can perform either addition(+) or subtraction(-)
// of every integer from the set to the 'total'. The resultant total should be
// equal to the value F.

// Your task is to find out the number of ways, you can make the 'total' equal to
// the value F.

// Input Format:
// -------------
// Line-1: Two integers N and F.
// Line-2: N space separated integers 

// Output Format:
// --------------
// Print an integer, number of ways.


// Sample Input:
// ---------------
// 5 3
// 1 1 1 1 1

// Sample Output:
// ----------------
// 5

// Explanation:
// ------------
// total = -1+1+1+1+1 = 3 -> total=value-F
// total = +1-1+1+1+1 = 3 -> total=value-F
// total = +1+1-1+1+1 = 3 -> total=value-F
// total = +1+1+1-1+1 = 3 -> total=value-F
// total = +1+1+1+1-1 = 3 -> total=value-F

// NOTE: + means addition, - means subtraction






#include<bits/stdc++.h>
using namespace std;
int c=0;
void solve(vector<int> &nums,int ind,int target,int &sum){
    if(ind==nums.size()){
        if(sum==target){
            c++;
        }
        return;
    }
    sum=sum+nums[ind];
    solve(nums,ind+1,target,sum);
    sum=sum-nums[ind];
    
    sum=sum-nums[ind];
    solve(nums,ind+1,target,sum);
    sum=sum+nums[ind];
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int sum=0;
    solve(nums,0,target,sum);
    cout<<c;
}
