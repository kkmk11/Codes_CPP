// Mr Akshay is playing with lines he is drawing lines with some height,imagin that two lines that together with the x-axis form a container, then find, with given integer heights maximum amount of water akshay can store,
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Return the maximum amount of water a container can store.
// input :
// number of lines n
// n integer values of height of each line
// output:
// maximum water a container can store

// Example 
// case 1:
// input :
// 9
// 1 8 6 2 5 4 8 3 7
// output= 49
// Explanation :
//  first line height is 1 second line height is 8 like that last line height is 7, so akshay can store water between second line and last line with the height of 7
//  distance between last and second line is 7 so maximum capacity is 7*7=49
//  note : if we consider two 8 lines i.e at position 2 and 7 then the height of container is 8 and distance of container is 5 so water capacity is 8 * 5 = 40
//  hence 49 is the maximum capacity returned.

// Case 2:
// input =9
// 1 2 3 4 5 6 7 8 9
// output = 20
// explanation :water is stored between line with height 5 and line with height 9 so height of container is 5 and width of container is 4 hence 5 * 4= 20
// case 3:
// input=10
// 1 1 1 1 1 1 1 10 8 10
// output=20




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int l=0,r=nums.size()-1,maxi=0;
    while(l<r){
        int x=min(nums[l],nums[r]);
        if(x==nums[l]){
            maxi=max(maxi,x*(r-l));
            l++;
        }
        else{
            maxi=max(maxi,x*(r-l));
            r--;
        }
    }
    cout<<maxi;
}
