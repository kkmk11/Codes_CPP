// /*
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].
// */




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    queue<int> q;
    vector<int> visited(n,false);
    q.push(0);
    visited[0]=true;
    int jumps=0;
    while(!q.empty()){
        jumps++;
        int c=q.size();
        for(int k=0;k<c;k++){
            int front=q.front();
            q.pop();
            if(front==nums.size()-1){
                cout<<jumps-1;
                exit(0);
            }
            for(int i=1;i<=nums[front];i++){
                if(i+front<=nums.size()-1 && visited[i+front]==false){
                    visited[i+front]=true;
                    q.push(i+front);
                }
            }
        }
    }
    cout<<jumps-1;
}
