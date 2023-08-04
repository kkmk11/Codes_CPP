// There are N constructions in pyramid structures, you are given the N pyramids 
// information as an array pyramids[], where pyramid[i]={center_of_base, peak} of 
// the pyramid. A pyramid is described as a right-angled isosceles triangle, 
// with its center of the base along the x-axis and a right angle at its peak. 
// More formally, the gradients of ascending and descending the pyramid are 1 
// and -1 respectively.

// A pyramid is considered visible if its peak does not lie within another pyramid 
// (including the border of other pyramids).

// Your task is to return the number of visible pyramids.

// Input Format:
// -------------
// Line-1: An integer N, number of pyramids
// Next N lines: Two space separated integers, center_of_base and peak.

// Output Format:
// --------------
// Print an integer result.


// Sample Input-1:
// ---------------
// 3
// 2 2
// 6 3
// 5 4

// Sample Output-1:
// ----------------
// 2

// Explanation:
// ------------
// Look in the hint.

// Sample Input-2:
// ---------------
// 2
// 2 4
// 2 4

// Sample Output-2:
// ----------------
// 0

// Explanation:
// ------------
// The structures on overlap on each other, so we will return 0.




#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (2,0));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    for(int i=0;i<v.size();i++){
        vector<int> x=v[i];
        x[0]=v[i][0]-v[i][1];
        x[1]=v[i][0]+v[i][1];
        v[i]=x;
    }
    sort(v.begin(),v.end(),[&](vector<int> a,vector<int> b){
       if(a[0]<b[0]){
           return true;
       } 
       else if(a[0]==b[0]){
           if(a[1]<b[1]){
               return true;
           }
           else{
               return false;
           }
       }
       else{
           return false;
       }
    });
    int c=n;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            if(i!=j){
                if(v[i][0]>=v[j][0] && v[i][1]<=v[j][1]){
                    c--;
                    break;
                }
            }
        }
    }
    cout<<c;
}
