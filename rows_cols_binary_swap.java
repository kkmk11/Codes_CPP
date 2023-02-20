// You have given a bulb grid, where the bulb which is turned ON is indicated 
// with 1, and turned OFF is indicated with 0.

// You are allowed to perform an operation:
//     - Select a row/column in the buld grid, and toggle the bulbs,
//     the bulbs which are turned ON will be truned OFF and the bulbs which are 
//     turned OFF will be turned ON.

// Your task is to find the highest possible sum of all the binary equivalents 
// of each row in the bulb grid, after performing the above operation any 
// number of times on the bulb grid.


// Input Format:
// -------------
// Line-1: Two space separated integers, M and N
// Next M lines: N space separated integers, grid[][]

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 3 5
// 0 1 1 1 1 
// 1 0 1 1 1 
// 0 0 0 0 1 

// Sample Output-1:
// ----------------
// 78

// Explanation:
// ------------
// Given grid is 
// 0 1 1 1 1
// 1 0 1 1 1
// 0 0 0 0 1

// Perform operation on row-0 and row-2
// 1 0 0 0 0
// 1 0 1 1 1
// 1 1 1 1 0

// Perform operation on col-1 and col-4
// 1 1 0 0 1 = 25
// 1 1 1 1 0 = 30
// 1 0 1 1 1 = 23
// So, now the total value of Binary Equivalent is 78


// Sample Input-2:
// ---------------
// 2 3
// 0 1 0
// 0 0 1

// Sample Output-2:
// ----------------
// 11


import java.util.*;
class j{
    static void flip(int[] g){
        for(int i=0;i<g.length;i++){
            if(g[i]==0){
                g[i]=1;
            }
            else{
                g[i]=0;
            }
        }
    }
    static int onescount(int[][] g,int j){
        int c=0;
        for(int i=0;i<g.length;i++){
            if(g[i][j]==1){
                c++;
            }
        }
        return c;
    }
    static void flipcol(int[][] g,int j){
        for(int i=0;i<g.length;i++){
            if(g[i][j]==0){
                g[i][j]=1;
            }
            else{
                g[i][j]=0;
            }
        }
    }
    static int bin(int[] g){
        int ans=0,ind=0;
        for(int i=g.length-1;i>=0;i--){
            ans+=Math.pow(2,ind++)*g[i];
        }
        // System.out.println(ans);
        return ans;
    }
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] g=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                g[i][j]=sc.nextInt();
            }
        }
        for(int []i:g){
            if(i[0]==0){
                flip(i);
            }
        }
        for(int i=0;i<m;i++){
            if(onescount(g,i)*2<n){
                flipcol(g,i);
            }
        }
        int ans=0;
        for(int[] i:g){
            ans=ans+bin(i);
        }
        System.out.println(ans);
    }
}
