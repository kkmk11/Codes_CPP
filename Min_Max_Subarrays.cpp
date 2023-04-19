// You are given an integer array nums and two integers minK and maxK.

// A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

// The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK.
// Return the number of fixed-bound subarrays.

// A subarray is a contiguous part of an array.
//  input = 4
//   1 1 1 1 
//   1
//   1
//   output = 10


// Example 1:

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
// Example 2:

// Input: nums = [1,1,1,1], minK = 1, maxK = 1
// Output: 10
// Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 
// Constraints:
// 2 <= nums.length <= 10^5
// 1 <= nums[i], minK, maxK <= 10^6
// */





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int min,max;
    cin>>min>>max;
    int c=0;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        int mini=INT_MAX,maxi=INT_MIN;
        while(l>=0 && r<v.size()){
            if(l==r){
                if(mini>v[l]){
                    mini=v[l];
                }
                if(maxi<v[l]){
                    maxi=v[l];
                }
            }
            else{
                if(mini>v[l]){
                    mini=v[l];
                }
                if(maxi<v[l]){
                    maxi=v[l];
                }
                if(mini>v[r]){
                    mini=v[r];
                }
                if(maxi<v[r]){
                    maxi=v[r];
                }
            }
            if(mini==min && maxi==max){
                c++;
            }
            l--;
            r++;
        }
        l=i,r=i+1,mini=INT_MAX,maxi=INT_MIN;
        while(l>=0 && r<v.size()){
            if(l==r){
                if(mini>v[l]){
                    mini=v[l];
                }
                if(maxi<v[l]){
                    maxi=v[l];
                }
            }
            else{
                if(mini>v[l]){
                    mini=v[l];
                }
                if(maxi<v[l]){
                    maxi=v[l];
                }
                if(mini>v[r]){
                    mini=v[r];
                }
                if(maxi<v[r]){
                    maxi=v[r];
                }
            }
            if(mini==min && maxi==max){
                c++;
            }
            l--;
            r++;
        }
    }
    cout<<c;
}
