// Given a string s, .reverse only all the vowels in the 
// string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can 
// appear in both lower and upper cases, more than once.

// Example 1:
// Input: hello
// Output: holle


// Example 2:
// Input: Keshavmemorial
// Output: Kashivmomerael

// Example 3:
// Input: variations
// Output: voriatians


#include<bits/stdc++.h>
using namespace std;
bool vowel(char k){
    if(k=='a' || k=='e' || k=='i' || k=='o' || k=='u'){
        return true;
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    while(l<=r){
        if(vowel(s[l]) && vowel(s[r])){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        else if(!vowel(s[l])){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<s;
}
