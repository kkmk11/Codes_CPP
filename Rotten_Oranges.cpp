// A dangerous virus "ebola" is spreading across african countries.
// Few people stand in a form of p*q grid, some positions in the grid are empty.

// The grid is represented with three values 0,1, 2.
// Where
// 	- 0 indicates an empty position,
// 	- 1 indiactes a healthy person , or
// 	- 2 indiactes an infected person.
	
// Every minute, any healthy person who is 4-directionally adjacent to an infected 
// person becomes infected.

// Your task is to find out the minimum amount of time in minutes that the virus 
// takes to spread among all the people in that grid.

// If this is impossible, return -1.

// NOTE:
// 4-directions are Up, Down, Left, Right.

// Input Format:
// -------------
// Line-1: Two integers P and Q, size of the grid.
// Next P lines: contains Q space separated integers, either 0, 1, or 2.

// Output Format:
// --------------
// An integer, the minimum amount of time in minutes


// Sample Input-1:
// ---------------
// 3 3
// 2 1 1
// 1 1 0
// 0 1 1

// Sample Output-1:
// ----------------
// 4

// Explanation-1:
// --------------
// There is an infected person at position (0, 0).
// In the first minute: people in (0, 1) and (1, 0) positions are infected.
// In the second minute: people in (0, 2) and (1, 1) positions are infected.
// In the third minute: person in (1, 2) position is infected.
// In the fourth minute: person in (2, 2) position is infected.


// Sample Input-2:
// ---------------
// 3 3
// 2 1 1
// 0 1 1
// 1 0 1

// Sample Output-2:
// ----------------
// -1

// Explanation-2:
// --------------
// The healthy person in the bottom left corner (row 2, column 0) is never infected, 
// because infection only happens 4-directionally.

// Sample Input-3:
// ---------------
// 1 2
// 0 2

// Sample Output-3:
// ----------------
// 0

// Explanation-3: 
// -------------
// Since there is already no healthy person at minute 0, the answer is just 0.





#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int k=0;
    queue<vector<int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                k++;
            }
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    if(k==0){
        cout<<0;
        exit(0);
    }
    int c=0;
    vector<vector<int>> nbrs={{0,1},{1,0},{0,-1},{-1,0}};
    while(!q.empty()){
        c++;
        int p=q.size();
        while(p>0){
            vector<int> v=q.front();
            q.pop();
            for(auto nbr:nbrs){
                int i=v[0]+nbr[0];
                int j=v[1]+nbr[1];
                if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
                    grid[i][j]=2;
                    q.push({i,j});
                    k--;
                }
            }
            p--;
        }
    }
    if(k==0){
        cout<<c-1;
    }
    else{
        cout<<-1;
    }
}
