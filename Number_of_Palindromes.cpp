// To get the admission into 6th standard in a reputed school in Hyderabad, 
// conducted an entrance test. one of the questions in the test was

// There was a sequence of characters(String) given, student has to check 
// in given String how many substrings are same as reverse of it (palindromic).

// Input Format:
// -------------
// Read a String.

// Output Format:
// --------------
// Print number of palindromic substrings of given string.



// Sample Input-1
// pqrs
// Sample Output-1
// 4

// Explanation: 
// "p", "q", "r", "s" are palindromic substrings of given string.


// Sample Input-2
// pppp
// Sample Output-2
// 10

// Explanation: 
// "p", "p", "p", "p", "pp", "ppp", "pppp", "pp", "ppp", "pp"  are 
// palindromic substrings of given string. 






#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int c=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int l=i,r=i;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            c++;
        }
        l=i,r=i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
            c++;
        }
    }
    cout<<c;
}
