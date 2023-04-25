// EA Sports, developed a video game. They designed a game in such a way that, 
// there are L number of levels from 1 to L. There are D number of dependencies
// where each dependency[m] = [ Xm, Ym ], represents a prerequisite relationship,
// that is, in order to play level-Ym, you must have completed the level-Xm.

// In one day you can complete any number of levels as long as you 
// have completed all the prerequisites levels in the game. 

// You cannot play a level-Ym which has some prerequisite level-Xm on same day.

// Write a method to return the minimum number of days to complete all the levels
// in the game. If there is no way to complete all the levels, return -1.


// Input Format:
// -------------
// Line-1: An integer L, number of levels.
// Line-2: An integer D, number of dependencies.
// Next D lines: Two space separated integers, Xm and Ym.

// Output Format:
// --------------
// An integer, the minimum number of days to complete all the levels in the game.


// Sample Input-1:
// ---------------
// 3
// 2
// 1 3
// 2 3

// Sample Output-1:
// ----------------
// 2

// Explanation-1:
// --------------
// On the first day, levels 1 and 2 are completed. 
// On the second day, level-3 is completed.


// Sample Input-2:
// ---------------
// 3
// 3
// 1 2
// 2 3
// 3 1

// Sample Output-2:
// ----------------
// -1

// Explanation-2:
// -------------
// No level can be completed because they depend on each other.





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,op;
    cin>>n;
    cin>>op;
    unordered_map<int,vector<int>> m;
    for(int i=0;i<op;i++){
        int x,y;
        cin>>x>>y;
        m[y].push_back(x);
    }
    vector<int> indg(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto x:m[i]){
            indg[x]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indg[i]==0){
            q.push(i);
        }
    }
    int c=0;
    vector<int> res;
    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            int front=q.front();
            q.pop();
            res.push_back(front);
            for(auto x:m[front]){
                indg[x]--;
                if(indg[x]==0){
                    q.push(x);
                }
            }
        }
        c++;
    }
    if(res.size()==n){
        cout<<c;
    }
    else{
        cout<<-1;
    }
}
