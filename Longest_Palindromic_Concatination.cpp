// Mr Gnanesh is working with words. He has given a list of words. 
// Each word in the list contains only two lowercase letters [a-z].

// He wants to create biggest word BW, by concatenating words from the list, which 
// is a palindrome too. He is allowed to use each word from the list atmost once.

// Return the length of the biggest word can be formed using the list.
// If it is impossible to create such word, return 0.

// Input Format:
// -------------
// Space separated strings, words[], two letter words.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// ab ba dd

// Sample Output-1:
// ----------------
// 6

// Explanation: 
// ------------
// The biggest word is, ab,dd,ba => abddba, which is a palindrome.


// Sample Input-2:
// ---------------
// pq rs sr mk km pq

// Sample Output-2:
// ----------------
// 8

// Explanation: 
// ------------
// The biggest word is, rs,sr,mk,km => rsmkkmsr or mkrssrkm..etc, 
// which is a palindrome.


// Sample Input-3:
// ---------------
// aa bb cc

// Sample Output-3:
// ----------------
// 2




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1;
    getline(cin,s1);
    stringstream x1(s1);
    string t1="";
    vector<string> v;
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    int res=0;
    unordered_map<string,int> m;
    for(string a:v){
        string s=a;
        reverse(s.begin(),s.end());
        if(m[s]>0){
            res=res+4;
            m[s]--;
        }
        else{
            m[a]++;
        }
    }
    for(auto key:m){
        string a=key.first;
        string s=a;
        reverse(s.begin(),s.end());
        if(s==a){
            res=res+2;
            break;
        }
    }
    cout<<res;
}
