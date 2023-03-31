// /*
// Mr Shravan is given a word W, and W cosists of lowercase alphabets and '#'. 
// Mr Shravan is allowed to replace the '#' with any one lowercase alphabet, 
// such that the word W is a palindrome and it has to be the lexicographically
// smallest among all the possible options.

// Your task is to help Mr Sharavan to return the lexicographically smallest 
// palindrome string among all the possible options. 
// OR "invlaid" if it is not possible.

// Input Format:
// -------------
// A String W, consists of lowercase letters and #.

// Output Format:
// --------------
// A String result.


// Sample Input-1:
// ---------------
// r#d#v##er

// Sample Output-1:
// ----------------
// redavader


// Sample Input-2:
// ---------------
// r#d#v#cer

// Sample Output-2:
// ----------------
// invalid





#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<s.size()/2;i++){
        if(s[i]=='#' && s[l-i-1]=='#'){
            s[i]='a';
            s[l-i-1]='a';
        }
        else if(s[i]=='#' && s[l-i-1]!='#'){
            s[i]=s[l-i-1];
        }
        else if(s[i]!='#' && s[l-i-1]=='#'){
            s[l-i-1]=s[i];
        }
        else{
            if(s[i]!=s[l-i-1]){
                cout<<"invalid";
                exit(0);
            }
        }
    }
    cout<<s;
}
