// Given a string of characters("<" or ">" or "?") where we have "?" which can be replace "?" as  per our convience
// which should form a longest symmetric substring from the given string.

// Note: Symmetric substring are like : "<<<>>>" , "<<>>" ,"<>" etc

// noew return the length of the longest symmetric substring taht can be obtained after replacing "?" with "<" or ">"

// example 1:
// s="<><??>>"
// output: 4

// example 2:
// s="<<?"
// output:2

// example 3:
// s="<><??>>"
// output:4



#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> left(n-1,0);
    vector<int> right(n-1,0);
    if(s[0]=='<' || s[0]=='?'){
        left[0]=1;
    }
    for(int i=1;i<n-1;i++){
        if(s[i]=='<' || s[i]=='?'){
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=0;
        }
    }
    if(s[n-1]=='>' || s[n-1]=='?'){
        right[n-2]=1;
    }
    for(int i=n-3;i>=0;i--){
        if(s[i+1]=='>' || s[i+1]=='?'){
            right[i]=right[i+1]+1;
        }
        else{
            right[i]=0;
        }
    }
    int ans=0;
    for(int i=0;i<left.size();i++){
        ans=max(ans,2*min(left[i],right[i]));
    }
    cout<<ans;
}
