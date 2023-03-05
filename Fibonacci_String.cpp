// Pramod is working on Strings consist of digits only. He wants to findout, 
// whether the given string can form Fibonacci sequence or not.

// A String can form a Fibonacci Sequence, if it contains at least 
// three numbers, and numbers are in the following order:
// first, second, third  = first + second, fourth = third + second, .. so on.

// Return true, if the given string can form fibonacci sequence,
// otherwise, return false.

// Note: Numbers in the fibonacci sequence contains no leading 0's.
// for example, 2, 03,5 or 2,3,05 or 02,3,5 are not valid.

// Input Format:
// -------------
// A String consist of digits only

// Output Format:
// --------------
// Print a boolean value as result.


// Sample Input-1:
// ---------------
// 23581321

// Sample Output-1:
// ----------------
// true

// Explanation: 
// ------------
// Fibonacci Sequence is : 2, 3, 5, 8, 13, 21
// 2, 3, 2+3=5, 3+5=8, 5+8=13, 8+13=21.

// Sample Input-2:
// ---------------
// 199100199

// Sample Output-2:
// ----------------
// true

// Explanation: 
// ------------
// Fibonacci Sequence is : 1 99 100 199
// 1, 99, 1+99=100, 99+100=199.






#include<bits/stdc++.h>
using namespace std;

vector<int> v;
bool solve(string &s,int ind){
    if(ind==s.size()){
        return v.size()>2;
    }
    int n=0;
    for(int i=ind;i<s.size();i++){
        if(i>ind && s[ind]=='0'){
            return false;
        }
        n=n*10+s[i]-'0';
        if(v.size()<2 || v[v.size()-1]+v[v.size()-2]==n){
            v.push_back(n);
            if(solve(s,i+1)){
                return true;
            }
            v.pop_back();
        }
    }
    return false;
}
int main(){
    string num;
    cin>>num;
    if(solve(num,0)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
