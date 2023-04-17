// Venkat wants to create a unique name for his child, to do that he is referring 
// two names, one is traditonal name(TN) and other is modern name(MN).

// He is planning to create unique name(UN), using the following ways:
//     - if traditional name TN is non empty, then add the first letter L of TN 
//     to unique name UN and remove the letter L from traditional name TN
// 	e.g., if TN = "havi" and UN="anvika", then after adding L to UN and remove L 
// 	from TN, the names updated as UN="hanvika", TN="avi".
   
//    - if modern name MN is non empty, then add the first letter L of MN 
//     to unique name UN and remove the letter L from modern name MN
//     e.g., if MN = "ram" and UN="ao", then after adding L to UN and remove L 
// 	from MN, the names updated as UN="rao", MN="am".
	
// You are given two names, TN and MN, 
// Your task is to help venkat to generate the unique name for his child,
// and the name should be largest in the dictionary order.

// For example, "kmit" is larger than "kmec", as third letter is greater in "kmit".

// Input Format:
// -------------
// Two space separated names, TN and MN.

// Output Format:
// --------------
// Print a string, the laregst unique name possible.


// Sample Input-1:
// ---------------
// sudha vivid

// Sample Output-1:
// ----------------
// vsuividhda


// Sample Input-2:
// ---------------
// appa banana

// Sample Output-2:
// ----------------
// bappananaa





#include<bits/stdc++.h>
using namespace std;
string res="";
void solve(int i,int j,string a,string b,string x){
    if(i>=a.size() || j>=b.size()){
        while(i<a.size()){
            x=x+a[i];
            i++;
        }
        while(j<b.size()){
            x=x+b[j];
            j++;
        }
        res=max(res,x);
        return;
    }
    if(a[i]>b[j]){
        solve(i+1,j,a,b,x+a[i]);
    }
    else if(a[i]<b[j]){
        solve(i,j+1,a,b,x+b[j]);
    }
    else{
        solve(i+1,j,a,b,x+a[i]);
        solve(i,j+1,a,b,x+b[j]);
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    string x="";
    solve(0,0,a,b,x);
    cout<<res;
}
