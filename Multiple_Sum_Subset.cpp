// Given a set of weights of n items weights[], and another item wieght w.
// Your task is to check if the sum of weights of continuous subset is equal to 
// one of the multiple of w, where subset size should be minimum 2.

// For example: Mulitple of w means, w=3 then multiple of w are
// 3, 6, 9, 12, .... so on.

// Print true, if such subset sum is possible.
// Otherwise, print false.

// Input Format:
// -------------
// Line-1 : Two integers n and w, number of weights and weight to match.
// Line-2 : n space separated integers, weights of n items.

// Output Format:
// --------------
// Print a boolean value.


// Sample Input-1:
// ---------------
// 5 4
// 1 2 3 5 6

// Sample Output-1:
// ----------------
// true


// Sample Input-2:
// ---------------
// 5 4
// 1 2 3 6 5

// Sample Output-2:
// ----------------
// true

// Explanation: 
// ------------
// sum of  continuous subset of weights [1,2,3,6]  equals to 12, multiple of 4.




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,w;
    cin>>n>>w;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        int l=i,r=i;
        int sum=0;
        while(l>=0 && r<nums.size()){
            if(l==r){
                sum=sum+nums[l];
            }
            else{
                sum=sum+nums[l]+nums[r];
            }
            if(sum%w==0 && (r-l+1)>=2){
                cout<<"true";
                exit(0);
            }
            l--;
            r++;
        }
        l=i,r=i+1;
        sum=0;
        while(l>=0 && r<nums.size()){
            if(l==r){
                sum=sum+nums[l];
            }
            else{
                sum=sum+nums[l]+nums[r];
            }
            if(sum%w==0&& (r-l+1)>=2){
                cout<<"true";
                exit(0);
            }
            l--;
            r++;
        }
    }
    cout<<"false";
}
