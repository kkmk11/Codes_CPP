/*You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.
 input = 4
  1 1 1 1 
  1
  1
  output = 10


Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 
Constraints:
2 <= nums.length <= 10^5
1 <= nums[i], minK, maxK <= 10^6
*/






#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int minK,maxK;
    cin>>minK;
    cin>>maxK;
    int c=0;
    int mini=-1,maxi=-1,x=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK){
            x=i;
        }
        if(nums[i]==minK){
            mini=i;
        }
        if(nums[i]==maxK){
            maxi=i;
        }
        c=c+max(0,min(mini,maxi)-x);
    }
    cout<<c;
}
