// Neeraj has a task to complete. Given a number N, he has to make reductions 
// to make it to 1 with the following rules:
//     1. If N is odd then add 1 to it.
//     2. If N is even then divide it by 2.
    
// Neeraj is given the N in binary format as a string S. Neeraj always 
// successful in making N to 1. 
// Your task is to help Neeraj to find the number of steps required to make N  to 1.

// Input Format:
// -------------
// A string S, represents the binary equivalent of N.

// Output Format:
// --------------
// Print an integer as number of steps.


// Sample Input-1:
// ---------------
// 110

// Sample Output-1:
// ----------------
// 4

// Explanation:
// -------------
// step-1: N=6, even, so 6/2=3
// step-2: N=3, odd,  so 3+1=4
// step-3: N=4, even, so 4/2=2
// step-4: N=2, even, so 2/2=1
// Total steps=4


// Sample Input-2:
// ---------------
// 101

// Sample Output-2:
// ----------------
// 5

// Explanation:
// ------------
// step-1: N=5, odd,  so 5+1=6
// step-2: N=6, even, so 6/2=3
// step-3: N=3, odd,  so 3+1=4
// step-4: N=4, even, so 4/2=2
// step-5: N=2, even, so 2/2=1
// Total steps=5




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int res=0;
    int carry=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]-'0'+carry==1){
            carry=1;
            res++;
        }
        res++;
    }
    cout<<res;
}
