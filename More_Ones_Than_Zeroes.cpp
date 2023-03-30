// You are given a binary array nums containing only the integers 0 and 1. Return the number of subarrays in nums that have more 1's than 0's. Since the answer may be very large, return it modulo 109 + 7.

// A subarray is a contiguous sequence of elements within an array.

//  Example 1:

// Input: nums = [0,1,1,0,1]
// Output: 9
// Explanation:
// The subarrays of size 1 that have more ones than zeros are: [1], [1], [1]
// The subarrays of size 2 that have more ones than zeros are: [1,1]
// The subarrays of size 3 that have more ones than zeros are: [0,1,1], [1,1,0], [1,0,1]
// The subarrays of size 4 that have more ones than zeros are: [1,1,0,1]
// The subarrays of size 5 that have more ones than zeros are: [0,1,1,0,1]
// Example 2:

// Input: nums = [0]
// Output: 0
// Explanation:
// No subarrays have more ones than zeros.
// Example 3:

// Input: nums = [1]
// Output: 1
// Explanation:
// The subarrays of size 1 that have more ones than zeros are: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 1





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        int l=i,r=i,one=0,zero=0;
        while(l>=0 && r<n){
            if(l==r){
                if(v[l]==1){
                    one++;
                }
                else{
                    zero++;
                }
            }
            else{
                if(v[l]==1){
                    one++;
                }
                if(v[r]==1){
                    one++;
                }
                if(v[l]==0){
                    zero++;
                }
                if(v[r]==0){
                    zero++;
                }
            }
            if(one>zero){
                res++;
            }
            l--;
            r++;
        }
        l=i,r=i+1,one=0,zero=0;
        while(l>=0 && r<n){
            if(l==r){
                if(v[l]==1){
                    one++;
                }
                else{
                    zero++;
                }
            }
            else{
                if(v[l]==1){
                    one++;
                }
                if(v[r]==1){
                    one++;
                }
                if(v[l]==0){
                    zero++;
                }
                if(v[r]==0){
                    zero++;
                }
            }
            if(one>zero){
                res++;
            }
            l--;
            r++;
        }
    }
    cout<<res;
}
