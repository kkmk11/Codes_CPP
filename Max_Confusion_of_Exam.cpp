// In a game, there are some questions in a row, and each question has two options 
// 'A' or 'B'. The organizer wants to confuse the participants by maximizing the 
// number of consecutive questions with the same option as valid answer. 
// (multiple As or multiple Bs in a row).

// The organizer is given a word 'options' and an integer P, where options[i] is 
// the valid answer to the ith question and P is the maximum number of times 
// you may perform the following operation:
//     - Change the options value for any question to 'A' or 'B' 
//       (i.e., set options[i] to 'A' or 'B').
// Your task is to return the maximum number of consecutive As or Bs in the options,
// after performing the operation at most P times.

// Input Format:
// -------------
// Line-1 -> A word, the options
// Line-2 -> An integer P, P number of operations.


// Output Format:
// --------------
// Print an integer as output.


// Sample Input-1:
// ---------------
// ABBABA
// 2

// Sample Output-1:
// ----------------
// 5

// Explanation:
// ------------
// We can replace any two 'A's at with 'B's. There are five consecutive 'B's.


// Sample Input-2:
// ---------------
// BABBABABAA
// 1

// Sample Output-2:
// ----------------
// 4


// Sample Input-3:
// ---------------
// BABBABABAA
// 2

// Sample Output-3:
// ----------------
// 6





#include<bits/stdc++.h>
using namespace std;
int solve(string s,char k,int n){
    int maxi=INT_MIN,c=0,p=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==k){
            c++;
        }
        while(c>n){
            if(s[p]==k){
                c--;
            }
            p++;
        }
        maxi=max(i-p+1,maxi);
    }
    return maxi;
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    cout<<max(solve(s,'A',n),solve(s,'B',n));
}
