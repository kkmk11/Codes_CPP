// You are given two words W1 and W2.
// You need find all the mapping of W2 in W1, and 
// return all the statrting indices of the mappings.

// The mapping of the words w2 and w1 is as follows:
// 	- A shuffled word contains all the characters as original word.
// 	The length of the words and occurrence count of each character are same.
// 	- find shuffled word of W2 as a substring in W1, and 
// 	return the starting index of substring.


// Input Format:
// -------------
// Single line space separated strings, two words.

// Output Format:
// --------------
// Print the list of integers, indices.


// Sample Input-1:
// ---------------
// abcabcabc abc
 
// Sample Output-1:
// ----------------
// [0, 1, 2, 3, 4, 5, 6]



// Sample Input-2:
// ---------------
// bacacbacdcab cab

// Sample Output-2:
// ----------------
// [0, 3, 4, 5, 9]




#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    vector<int> bl(26,0);
    for(auto i:b){
        bl[i-'a']++;
    }
    vector<int> al(26,0);
    vector<int> res;
    int p=0;
    for(int i=0;i<b.size();i++){
        al[a[i]-'a']++;
    }
    if(al==bl){
        res.push_back(p);
    }
    p++;
    int j=0;
    for(int i=b.size();i<a.size();i++){
        al[a[j]-'a']--;
        al[a[i]-'a']++;
        if(al==bl){
            res.push_back(p);
        }
        j++;
        p++;
    }
    for(int i:res){
        cout<<i<<" ";
    }
}
