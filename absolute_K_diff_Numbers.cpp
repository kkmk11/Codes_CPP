// Basanthi interested playing with digits.
// He wants create a set of integers of length N, using the digits[0-9].
// The rules to create the integers are as follows:
// 	- digits in each integer are like d0,d1,d2...dn-1
// 	- and |d0-d1| = |d1-d2| = |d2-d3| ... |dn-2 - dn-1|= D

// Basanthi is given two integers N and D, where N is length of the integer and 
// D is the difference. Can you help Basanthi, to create such list of integers 
// and print all the possible integers in ascending order


// Note:
// -----
// Integers with leading 0's are not allowed


// Input Format:
// -------------
// Two space separated integers N and K.

// Output Format:
// --------------
// Print all the possible integers in ascending order.


// Sample Input-1:
// ---------------
// 3 6

// Sample Output-1:
// ----------------
// [171, 282, 393, 606, 717, 828, 939]


// Sample Input-2:
// ---------------
// 2 3

// Sample Output-2:
// ----------------
// [14, 25, 30, 36, 41, 47, 52, 58, 63, 69, 74, 85, 96]




#include<bits/stdc++.h>
using namespace std;
vector<int> res;
void solve(string &s,string x,int n,int k){
    if(x.size()==n){
        res.push_back(stoi(x));
        return;
    }
    for(int i=0;i<s.size();i++){
        if(x.size()==0 || (x[0]!='0' && abs((x.back()-'0')-(s[i]-'0'))==k)){
            x=x+s[i];
            solve(s,x,n,k);
            x.pop_back();
        }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    string s="0123456789";
    string x="";
    solve(s,x,n,k);
    for(auto i:res){
        cout<<i<<" ";
    }
}
