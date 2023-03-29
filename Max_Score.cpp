// You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
// The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, 
// that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

// Example 1:

// Input: nums = 5
// 4 2 4 5 6
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    // 4 2 4 4 5
    unordered_map<int,int> m;
    int maxi=INT_MIN,sum=0,k=0;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
        sum=sum+nums[i];
        while(m[nums[i]]>1){
            sum=sum-nums[k];
            m[nums[k]]--;
            k++;
        }
        maxi=max(maxi,sum);
    }
    cout<<maxi;
}
