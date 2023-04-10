// Gnanesh is working on Machine Learning domain. He wants train the machine 
// in such a way that, if he provided an image printed with a string on it,
// the machine has to extract the text as a string and verify that, 
// after shuffling  the letters in the string, 'the shuffled string should be 
// like no two adjacent letters should be same' 

// You will be given extracted string, and
// Can you help Gnanesh to train the machine with the given constraint 
// The machine has to print "true", if the constarint is met, 
// Otherwise, print "false".

// Input Format:
// -------------
// A String S

// Output Format:
// --------------
// Print a boolean value.


// Sample Input-1:
// ---------------
// aaabd

// Sample Output-1:
// ----------------
// true

// Sample Input-2:
// ---------------
// aaab

// Sample Output-2:
// ----------------
// false





#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(auto i:s){
        m[i]++;
    }
    int x=0;
    if(s.size()%2!=0){
        x=s.size()/2+1;
    }
    else{
        x=s.size()/2;
    }
    for(auto key:m){
        if(key.second>x){
            cout<<"false";
            exit(0);
        }
    }
    cout<<"true";
}
