// Andy and Berry are serving water to n guests at their home. 
// The guests are seated in a row and are labeled from 0 to n - 1 
// from left to right where the ith guest is sitting at x = i.

// Each guest needs a specific amount of water. 
// Andy and Berry have a water jar each, initially full. 
// They serve water in the following way:

// Andy serves water to the guests in order from left to right, 
// starting from the 0th guest. 
// Berry serves water to the guests in order from right to left, 
// starting from the (n - 1)th guest. They begin to serve simultaneously.

// It takes the same amount of time to serve each guest 
// regardless of how much water they need.
// Andy/Berry must serve water to the guests if there is enough water 
// in their jar to fully fill the guest's glass. Otherwise, 
// they first refill their jar (instantaneously) and then serve water to the guest.

// In case both Andy and Berry reach the same guest, 
// the one with more water currently in his water jar should serve water. 
// If they have the same amount of water, then Andy has to serve water to the guest.

// Given a 0-indexed integer array guests of n integers, 
// where guests[i] is the amount of water the ith guest needs, 
// and two integers capacityA and capacityB representing the 
// capacities of Andy's and Berry's water jars respectively, 
// return the number of times they have to refill to server water to all the guests.
 

// Example 1:

// Input: guests = [2,2,3,3], capacityA = 5, capacityB = 5
// Output: 1
// Explanation:
// - Initially, Andy and Berry have 5 units of water each in their water jar.
// - Andy serves water to guest 0, Berry serves water to guest 3.
// - Andy and Berry now have 3 units and 2 units of water respectively.
// - Andy has enough water for guest 1, so she serves the guest. 

// Berry does not have enough water for guest 2, so he refills his jar and then serves the guest.
// So, the total number of times they have to refill to serve all the guests is 0 + 0 + 1 + 0 = 1.


// Example 2:

// Input: guests = [2,2,3,3], capacityA = 3, capacityB = 4
// Output: 2
// Explanation:
// - Initially, Andy and Berry have 3 units and 4 units of 
// water in their water jars respectively.
// - Andy serves guest 0, and Berry serves guest 3.
// - Andy and Berry now have 1 unit of water each, 
// and need to serve water to guests 1 and 2 respectively.
// - Since neither of them has enough water for their current guests, 
// they refill their jars and then serves them.

// So, the total number of times they have to refill to serve all the guests is 0 + 1 + 1 + 0 = 2.
// Example 3:

// Input: guests = [5], capacityA = 10, capacityB = 8
// Output: 0
// Explanation:
// - There is only one guest.
// - Andy's water jar has 10 units of water, whereas Berry's has 8 units. Since Andy has more water in his can, he serves this guest.
// So, the total number of times they have to refill is 0.




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ca,cb;
    cin>>ca>>cb;
    int ta=ca,tb=cb;
    int l=0,r=nums.size()-1,c=0;
    while(l<=r){
        if(l==r){
            if(ta>tb){
                if(nums[l]>ta){
                    c++;
                }
            }
            else{
                if(nums[l]>tb){
                    c++;
                }
            }
            break;
        }
        if(nums[l]>ta){
            ta=ca;
            c++;
        }
        if(nums[r]>tb){
            tb=cb;
            c++;
        }
        ta=ta-nums[l];
        tb=tb-nums[r];
        r--;
        l++;
    }
    cout<<c;
}
