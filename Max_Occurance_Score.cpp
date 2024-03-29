// There are N players, played a game.
// You are given the scores of the N players as scores[] array,
// where i-th player score is score[i].
// You are given P chances to modify the score of the players.

// In each chance you can modify the score of i-th (0 <= i < N) player as follows:
// 	- You are allowed increment the score of i-th player by 1.
// You have to perform these increments, in order to maximize the occurences of any score.

// Your task is to maximize occurences of a score, after utlizing atmost P chances.

// Input Format:
// -------------
// Line-1: Two space separated integers N and P, Players count, and number of chances.
// Line-2: N space separated integers, scores of N players scores[].

// Output Format:
// --------------
// Print an integer, maximum occurences of a score!


// Sample Input-1:
// ---------------
// 5 3
// 2 3 5 6 9

// Sample Output-1:
// ----------------
// 2


// Sample Input-2
// ---------------
// 6 5
// 2 3 4 6 8 9

// Sample Output-2:
// ----------------
// 3




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,c=0;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int maxi=INT_MIN;
    for(int i=v.size()-1;i>=0;i--){
        int c=0,p=k;
        for(int j=i;j>=0;j--){
            if(p-(v[i]-v[j])>=0){
                p=p-(v[i]-v[j]);
                c++;
            }
            else{
                break;
            }
        }
        maxi=max(maxi,c);
    }
    cout<<maxi;
}
