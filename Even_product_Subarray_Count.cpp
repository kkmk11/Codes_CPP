// Given an array of integer elements, ele[], YOur task is to find and print 
// the number of the subarrays, which gives you an even value after multiplication
// of the elements in it.

// Input Format:
// -------------
// Line-1: An integer N, number of elements.
// Line-2: Space separated elements.

// Output Format:
// --------------
// Print number of possible subarrays.


// Sample Input-1:
// ---------------
// 4
// 5 8 9 17

// Sample Output-1:
// ----------------
// 6

// Explanation:
// ------------
// 5 x 8 = 40
// 5 x 8 x 9 = 360
// 5 x 8 x 9 x 17 = 6120
// 8 = 8
// 8 x 9 = 72
// 8 x 9 x 17 = 1224
// Hence we got 6 even subarray multiplications.



// Sample Input-2:
// ---------------
// 3
// 5 7 11

// Sample Output-2:
// ----------------
// 0

// Explanation:
// ------------
// No subarrays which will give you even value after multiplication.





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c=0;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<nums.size();i++){
        int l=i,r=i,x=1;
        while(l>=0 && r<nums.size()){
            if(l==r){
                x=x*nums[l];
            }
            else{
                x=x*nums[l]*nums[r];
            }
            if(x%2==0){
                c++;
            }
            l--;
            r++;
        }
        l=i,r=i+1,x=1;
        while(l>=0 && r<nums.size()){
            if(l==r){
                x=x*nums[l];
            }
            else{
                x=x*nums[l]*nums[r];
            }
            if(x%2==0){
                c++;
            }
            l--;
            r++;
        }
    }
    cout<<c;
}




// soltuion2:
// int getAns(vector<int> nums){
//     int n = nums.size();
//     int res = (n*(n+1))/2;
//     int c=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]%2!=0){
//             c++;
//         }
//         else{
//             res=res-(c*(c+1))/2;
//             c=0;
//         }
//     }
//     res=res-(c*(c+1))/2;
//     return res;
// }
