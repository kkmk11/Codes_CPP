// You are given a 0-indexed integer array nums.

// We say that an integer x is expressible from nums if there exist some integers 0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.

// Return the minimum positive non-zero integer that is not expressible from nums.

// Input = 2
// 2 1
// output = 4

// Example 1:
// Input: nums = [2,1]
// Output: 4
// Explanation: 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.

// Example 2:
// Input: nums = [5,3,2]
// Output: 1
// Explanation: We can show that 1 is the smallest number that is not expressible.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109




#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &v){
    sort(v.begin(),v.end());
    int k=1;
    for(int i:v){
        if(i>k){
            return k;
        }
        if(i==k){
            k=k*2;
        }
    }
    return k;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v);
}
