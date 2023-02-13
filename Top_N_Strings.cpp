// Sridhar brought his latest Apple iPhone 12 pro. He started his conversation 
// with one of his friend on WhatsApp with list of words.

// Now it’s our task to find and return what are the most common words 
// in the list of words he used in sorted order based on occurrence from 
// largest to smallest. If any of words he used are having same occurrence 
// then consider the lexicographic order.

// You will be given a list of words, you need to print top P number of 
// most common used words as described in the statement. 

// Input Format:
// -------------
// Line-1: comma separated line of words, list of words.
// Line-2: An integer P, number of words to display. 

// Output Format:
// --------------
// Print P number of most common used words.


// Sample Input-1:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are,case
// 3

// Sample Output-1:
// ----------------
// [are, case, egg]



// Sample Input-2:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are
// 3

// Sample Output-2:
// ----------------
// [are, egg, case]



#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> m;
    int n,c=0;
    string s1,t1;
    getline(cin,s1);
    cin>>n;
    stringstream x1(s1);
    vector<int> v;
    while(getline(x1,t1,',')){
        m[t1]++;
    }
    vector<string> res;
    map<int,set<string>,greater<int>> m1;
    for(auto key:m){
        m1[key.second].insert(key.first);
    }
    for(auto key:m1){
        if(c<n){
            for(auto i:key.second){
                if(c<n){
                c++;
                res.push_back(i);
                }
                else{
                    break;
                }
            }  
        }
        else{
            break;
        }
    }
    for(auto i:res){
        cout<<i<<" ";
    }
}
