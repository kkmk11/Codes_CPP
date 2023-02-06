// Clavius, the person who suggested grouping of data using brackets.
// He has suggested that the group of brackets should be Well-Formed.

// A string is said to be Well-Formed, if:
//     - Any open bracket must have corresponding two consecutive close brackets.
//     - Open bracket must appear before the corresponding close brackets.

// You will be given a string B, consists of square brackets only '[' , ']'.
// In one operation, you can insert one square bracket at any position of B.
// i.e., Given B = [[]]], in one operation you can add a open square bracket,
// now B can be Well-Formed string, if you add at index 2,3,4 or 5 => [[]]]]

// Your task is to return the least number of operations required,
// to make B as a Well-Formed string.

// Input Format:
// -------------
// A string, B contains only characters '[', ']'

// Output Format:
// --------------
// Print an integer value.


// Sample Input-1:
// ---------------
// []]][

// Sample Output-1:
// ----------------
// 4


// Sample Input-2:
// ---------------
// []][[]]

// Sample Output-2:
// ----------------
// 2


#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> st;
    int close=0,open=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(i<s.size()-1 && s[i+1]==']'){
                if(!st.empty() && st.top()=='[' && s[i+1]==']'){
                    st.pop();
                }
                else{
                    open++;
                }
                i++;
            }
            else{
                if(!st.empty() && st.top()=='['){
                    close++;
                    st.pop();
                }
                else if(st.empty()){
                    open++;
                    close++;
                }
            }
        }
    }
    cout<<2*st.size()+open+close;
}
