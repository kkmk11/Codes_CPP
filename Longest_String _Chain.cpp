// Mr Saurabh is given a list of words.
// Your task is to help Mr Saurabh to find the size of largest group

// A group is formed using the following rules:
// - Pick one smallest word (in length) and form a group with this word
//   (if it is not part of any other group yet)
// - Add a letter at any place in the word without changing the relative order 
//   of the letters in it, and if it forms a word which is existing in the list[],
//   then add the word to the group.
// - Repeat the above two steps, till all the words in the list are part of groups.

// NOTE:You move form more than one group.

// Input Format:
// -------------
// Space separated words, wordsList[].

// Output Format:
// --------------
// Print an integer result


// Sample Input-1:
// ---------------
// many money n an mony any one mone on


// Sample Output-1:
// ----------------
// 5

// Explanation:
// ------------
// the words group is : [n, on, one, mone, money]


// Sample Input-2:
// ---------------
// a ab abb babb abab baba bab abbaa

// Sample Output-2:
// ----------------
// 4




#include<bits/stdc++.h>
using namespace std;
bool isSubSequence(string a,string b){
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return j==b.size();
}
int main(){
    string s;
    getline(cin,s);
    vector<string> v;
    stringstream x1(s);
    string t1="";
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    sort(v.begin(),v.end(),[&](string a,string b){
       if(a.size()<b.size()){
           return true;
       } 
       else{
           return false;
       }
    });
    int maxi=1;
    vector<int> dp(v.size(),1);
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[i].size()-v[j].size()==1){
                if(isSubSequence(v[i],v[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        maxi=max(maxi,dp[i]);
    }
    cout<<maxi;
}
