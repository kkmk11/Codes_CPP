// During her interview session, Ms. Sathvika faces an intriguing question. The interviewer presents her with a positive integer n. The challenge is to break down this integer into a sum of k positive integers (where k >= 2) and then maximize the product of these integers. Finally, she has to print the maximum product using those k positive integers
// Can you assist Ms. Sathvika in impressing the interviewer with a java program.

// Return the maximum product you can get.

// inpurt format : integer number n
// output format : integer number m

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.

// Example 2:

// Input: n = 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

// Constraints:
// 2 <= n <= 58




#include<bits/stdc++.h>
using namespace std;
int maxi=INT_MIN;
void solve(vector<int> &v,int target,int ind,int product){
    if(ind==v.size()){
        return;
    }
    if(target==0){
        maxi=max(maxi,product);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=ind;i<v.size();i++){
        if(target<v[i]){
            break;
        }
        product=product*v[i];
        solve(v,target-v[i],i,product);
        product=product/v[i];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<n;i++){
        v.push_back(i);
    }
    solve(v,n,0,1);
    cout<<maxi;
}
