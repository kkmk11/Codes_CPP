// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9





class Solution {
public:
    vector<vector<string>> v;
    bool safe(vector<vector<int>> &grid,int row,int col){
        for(int i=row;i>=0;i--){
            if(grid[i][col]==1){
                return false;
            }
        }
        for(int i=col;i>=0;i--){
            if(grid[row][i]==1){
                return false;
            }
        }
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(grid[r][c]==1){
                return false;
            }
            r--;
            c--;
        }
        r=row,c=col;
        while(r>=0 && c<grid[0].size()){
            if(grid[r][c]==1){
                return false;
            }
            r--;
            c++;
        }
        // r=row,c=col;
        // while(r<grid.size() && c>=0){
        //     if(grid[r][c]==1){
        //         return false;
        //     }
        //     r++;
        //     c--;
        // }
        // r=row,c=col;
        // while(r<grid.size() && c<grid[0].size()){
        //     if(grid[r][c]==1){
        //         return false;
        //     }
        //     r++;
        //     c++;
        // }
        return true;
    }
    void solve(vector<vector<int>> &grid,int row){
        if(row==grid.size()){
            vector<string> p;
            for(int k=0;k<grid.size();k++){
                string s="";
                for(int l=0;l<grid[0].size();l++){
                    if(grid[k][l]==1){
                        s=s+'Q';
                    }
                    else{
                        s=s+'.';
                    }
                }
                p.push_back(s);
            }
            v.push_back(p);
            return;
        }
        for(int col=0;col<grid[0].size();col++){
            if(safe(grid,row,col)){
                grid[row][col]=1;
                solve(grid,row+1);
                grid[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> grid(n,vector<int> (n,0));
        solve(grid,0);
        return v;
    }
};
