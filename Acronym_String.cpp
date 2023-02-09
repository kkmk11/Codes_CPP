// Ananth interested in creating the acronyms for any word. The definition
// of acronym is another word with a concatenation of its first letter,
// the number of letters between the first and last letter, and its last letter. 
 
// If a word has only two characters, then it is an acronym of itself.

// Examples:
//     - Acronym of 'fog' is f1g'.
//     - Acronym of 'another' is 'a5r'.
//     - Acronym of 'ab' is 'ab'.

// You are given a list of vocabulary, and another list of words.
// Your task is to check,each word with the vocabulary and
// return "true" if atleast one of the following rules satisfied:
// 1. acronym of the word should not match with any of the acronyms of vocabulary
// 2. if acronym of the word matches with any of the acronyms of vocabulary
// 'the word' and matching words in vocabulary should be same.

// Otherwise, return 'false'.

// Input Format:
// -------------
// Line-1: Space separated strings, vocabulary[] 
// Line-2: Space separated strings, words[] 

// Output Format:
// --------------
// Print N boolean values, where N = words.length 


// Sample Input-1:
// ---------------
// cool bell cool coir move more mike
// cool char move 

// Sample Output-1:
// ----------------
// true false false



#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> v1;
    string s1,t1;
    getline(cin,s1);
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        v1.push_back(t1);
    }
    string s2,t2;
    getline(cin,s2);
    stringstream x2(s2);
    while(getline(x2,t2,' ')){
        int flag=0;
        for(string s:v1){
            if(t2[0]==s[0] && t2[t2.size()-1]==s[s.size()-1]){
                if(t2==s){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            cout<<"true"<<" ";
        }
        else{
            cout<<"false"<<" ";
        }
    }
}
