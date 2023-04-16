// /*
// Mr. Gnanesh is working with words. He has given a list of words. 
// Each word in the list contains only two lowercase letters [a-z].

// He wants to create the biggest word BW, by concatenating words from the list, which 
// is a palindrome too. He is allowed to use each word from the list at most once.

// Return the length of the biggest word that can be formed using the list.
// If it is impossible to create a such word, return 0.

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
    string t1;
    vector<string> v;
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    int sum=0;
    unordered_map<string,int> m;
    for(auto a:v){
        string s=a;
        reverse(s.begin(),s.end());
        if(m[s]>0){
            sum=sum+4;
            m[s]--;
        }
        else{
            m[a]++;
        }
    }
    for(auto key:m){
        string s=key.first;
        reverse(s.begin(),s.end());
        if(key.second>0 && key.first==s){
            sum=sum+2;
            break;
        }
    }
    cout<<sum;
}
