// Aruna as a type writer, typing a document in her laptop. Suddently her system got
// hacked and whatever she types as words are displaying in reverse and with simple 
// braces. She types only lowercase letters.

// Inorder to get the actual words, Aruna has to reverse each word starting with the
// word which is in innermost most braces and remove those braces.
// Help Aruna to get actual words.

// Constraints:
// ------------
//   - 0 <= word.length <= 2000
//   - Word only contains lower case English characters and parentheses.
//     It's guaranteed that all braces are balanced.


// Input Format:
// -------------
// Line-1: a string represents an encoded word.

// Output Format:
// --------------
// return the original string.


// Sample Input-1:
// ---------------
// (pqrs)

// Sample Output-1:
// ----------------
// srqp


// Sample Input-2:
// ---------------
// (uoy(are)woh)

// Sample Output-2:
// ----------------
// howareyou

// Explanation
// ------------
// Initially "are" will be revesed as "era".
// Then (uoyerawoh) will be reversed.




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> st;
    for(char i:s){
        if(i=='('){
            st.push('(');
        }
        else if(i==')'){
            string x="";
            while(st.top()!='('){
                x=x+st.top();
                st.pop();
            }
            st.pop();
            for(char i:x){
                st.push(i);
            }
        }
        else{
            st.push(i);
        }
    }
    string res="";
    while(!st.empty()){
        res=st.top()+res;
        st.pop();
    }
    cout<<res;
}
