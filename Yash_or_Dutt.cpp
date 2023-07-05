// In a game, There are N boxes in a Queue.
// Each box conatins few gold coins in it.

// Yash and Dutt are playing the game.

// Game rules are as follows:
// 	- Initially, Yash picks one of the box from either end of the Queue.
// 	- Then, Dutt picks one of the box from either end of the Queue.
// 	- Repeat the first and second steps until the Queue become empty. 
// The person with the maximum amount of gold coins is the winner.

// You are given N boxes of gold coins, coins[].
// Your task is to find the name of the winner either Yash or Dutt. 

// Input Format:
// -------------
// Line-1: An integer N
// Line-2: N space separated integers coins[].

// Output Format:
// --------------
// Print the name of the winner, Yash / Dutt


// Sample Input-1:
// ---------------
// 3
// 2 6 3

// Sample Output-1:
// ----------------
// Dutt

// Explanation: 
// ------------
// Initially, Yash can choose between 2 and 3.
// If he chooses 3 (or 2), then Dutt can choose from 2 (or 3) and 5. If player 2 chooses 5, then
// Yash will be left with 2 (or 3).
// So, final score of Yash is 3 + 2 = 5, and Dutt is 6.
// Hence, Dutt is the winner.

// Sample Input-2:
// ---------------
// 4
// 2 6 50 7

// Sample Output-2:
// ----------------
// Yash



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ys=0,ds=0;
    bool yash=true;
    int l=0,r=n-1;
    while(l<=r){
        if(nums[l]>=nums[r]){
            if(yash){
                ys=ys+nums[l];
            }
            else{
                ds=ds+nums[l];
            }
            l++;
        }
        else{
            if(yash){
                ys=ys+nums[r];
            }
            else{
                ds=ds+nums[r];
            }
            r--;
        }
        if(yash){
            yash=false;
        }
        else{
            yash=true;
        }
    }
    if(ys>ds){
        cout<<"Yash";
    }
    else{
        cout<<"Dutt";
    }
}
