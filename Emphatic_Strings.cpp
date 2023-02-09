// "Emphatic Pronunciation" of a given word is where we take the word and
// replicate some of the letter to emphasize their impact.

// Instead of saying 'oh my god', someone may say "ohhh myyy goddd", 
// We define emphatic pronunciation of a word, which is derived by replicating 
// a group (or single) of letters in the original word. 

// So that the replicated group is atleast 3 characters or more and 
// greater than or equal to size of original group. 
// For example Good -> Goood is an emphatic pronunciation,
// but Goodd is not because in Goodd the 'd' are only occuring twice consecutively.
 
// In the question you are given the "Emphatic pronunciation" word, 
// you have to findout how many words can legal result in the 
// "emphatic pronunciation" word.

// Input Format:
// -------------
// Line-1 -> A String contains a single word, Emphatic Pronunciation word
// Line-2 -> Space seperated word/s

// Output Format:
// --------------
// Print an integer as your result


// Sample Input-1:
// ---------------
// Goood
// Good

// Sample Output-1:
// ----------------
// 1


// Sample Input-2:
// ---------------
// heeelllooo
// hello hi helo

// Sample Output-2:
// ----------------
// 2



#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string word){
    int i = 0, j = 0;
    if(word.length() > s.length())
        return false;
    while(i < s.length() and j < word.length()){
        if(s[i] != word[j])
            return false;
        i++, j++;
        int cnt1 = 1, cnt2 = 1;
        while(i < s.length() and s[i] == s[i - 1])
            cnt1++, i++;
        while(j < word.length() and word[j] == word[j - 1])
            cnt2++, j++;
        if(cnt2 > cnt1)
            return false;
        if(cnt1 < 3)
            if(cnt1 != cnt2)
                return false;
    }
    if(i == s.length() and j == word.length())
        return true;
    return false;
 }
int main(){
    vector<string> v;
    string s;
    getline(cin,s);
    string s1,t1;
    getline(cin,s1);
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    int ans=0;
    for(auto word: v){
        ans = solve(s, word) ? ans + 1 : ans;
    }
    cout<<ans;
}
