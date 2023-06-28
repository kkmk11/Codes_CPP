// Mark is playing a game where he is trying to save the city of Atlantis 
// by throwing grenades at a monster which is trying to destroy the city. 
// Once a monster gets hit with a grenade, it stays inactive for d seconds. 
// So let's say, if monster gets hit at second t, it will stay inactive during 
// the inclusive time interval [t,t+d-1]. If another grenade is thrown before 
// the effect of previous one ends, the monster remains inactive until seconds 
// after this new attack. 

// Given an array of non-decreasing integers attack, where attack[i] represents
// that a grenade is thrown at attack[i]-th second, and the value of integer
// duration d, you need to return the total number of seconds that the monster
// stayed inactive. 


// Constraints: 
// • attack is sorted in non-decreasing order. 
// • 1 <= attack.length <= 10^4 
// • 0 <= attack[i], d <= 10^7 


// Sample Input-1:
// ---------------
// 2 3     // n and d values
// 1 5     // attack[] values


// Sample Output-2:
// ----------------
// 6


// Sample Input-2:
// ---------------
// 3 5
// 1 3 5

// Sample Output-2:
// ----------------
// 9




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> nums;
    for(int t:v){
        nums.push_back({t,t+d-1});
    }
    vector<vector<int>> arr;
    arr.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(arr.back()[1]>=nums[i][0]){
            arr.back()[1]=max(arr.back()[1],nums[i][1]);
        }
        else{
            arr.push_back(nums[i]);
        }
    }
    int sum=0;
    for(auto x:arr){
        sum=sum+(x[1]-x[0]+1);
    }
    cout<<sum;
}
