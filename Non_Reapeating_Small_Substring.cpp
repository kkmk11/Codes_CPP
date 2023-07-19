// Mr Shravan is given a word W, and W cosists of lowercase alphabets only. 
// Mr Shravan is interested to find the substring which is smallest in length 
// the which occurs only one in the word W.

// Your task is to help Mr Sharavan to return the length of the smallest 
// substring of W according to the above statement.

// Input Format:
// -------------
// A String W, consists of lowercase letters.

// Output Format:
// --------------
// An integer result.


// Sample Input-1:
// ---------------
// abbaabab

// Sample Output-1:
// ----------------
// 2


// Sample Input-2:
// ---------------
// rererer

// Sample Output-2:
// ----------------
// 5




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<string,int> m;
    for(int i=0;i<s.size();i++){
        int l=i;
        int r=i;
        string x="";
        while(l>=0 && r<s.size()){
            x=s.substr(l,r-l+1);
            m[x]++;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        x="";
        while(l>=0 && r<s.size()){
            x=s.substr(l,r-l+1);
            m[x]++;
            l--;
            r++;
        }
    }
    int mini=s.size();
    for(auto key:m){
        if(key.second==1){
            if(mini>key.first.size()){
                mini=key.first.size();
            }
        }
    }
    cout<<mini;
}
