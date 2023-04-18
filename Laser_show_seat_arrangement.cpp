// The laser show at the Lumbini Park is something not to be missed.
// But, as per govt rule they have to follow COVID-19 restrictions.
// The management planning to guide the audience to sit in the seats
// that maximizes the distance to the closest person, in order to
// practice the social distance in the auditorium.

// Please help usher to guide the audience to sit in a seat by following few rules:

// - There are N seats in a single row, seats are numbered from 0 to N-1.
// - Maximize the distance from person to the closest person.
// - If there are multiple seats with similar distance, they sit in the seat with the lowest number.
// - First person always sit in seat number 0.
// - If a person leaves the auditorium from a seat, please consider that the seat is vacant

// Create a class Auditorium and two functions in it.
// 1. int seat(): represent the seat number of audience to sit.
// 2. void leave(int s): person leaves the auditorium from a seat number 's'.

// Input Format:
// ----------------
// Line-1 -> two integers N and P, Number of seats N, Number of Operations P
// P lines of input -> each line contains funtion number and parameter list (if required).

// Output Format:
// ------------------
// Print the alloted seat numbers in one line as output.


// Sample Input-1:
// -------------------
// 10 6
// 1
// 1
// 1
// 1
// 2 4
// 1

// Sample Output-1:
// ---------------------
// 0 9 4 2 5

// NOTE:
// -----
// In the sample input:
//     - option 1 indicates, calling "int seat()" method.
//     - option 2 indicates, calling "void leave(seat_num)" method.
    



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    cin>>n>>p;
    vector<int> v(n,0);
    vector<int> ans;
    for(int i=0;i<p;i++){
        int op;
        cin>>op;
        if(op==1){
            if(i==0){
                v[i]=-1;
                ans.push_back(i);
            }
            else if(i==1){
                v[v.size()-1]=-1;
                ans.push_back(v.size()-1);
            }
            else{    // -1 0 0 0 -1 0 0 -1 0 -1
                if(v[0]!=-1){
                    v[0]=-1;
                    ans.push_back(0);
                }
                else if(v[v.size()-1]!=-1){
                    v[v.size()-1]=-1;
                    ans.push_back(v.size()-1);
                }
                else{
                int maxi=INT_MIN;
                int point=0;
                vector<int> res;
                for(int j=0;j<v.size();j++){
                    if(v[j]==-1){
                        res.push_back(j);
                    }
                }
                for(int j=0;j<res.size()-1;j++){
                    if(maxi<abs(res[j]-res[j+1])/2){
                        maxi=abs(res[j]-res[j+1])/2;
                        point=(res[j]+res[j+1])/2;
                    }
                }
                v[point]=-1;
                if(point!=0){
                    ans.push_back(point);
                }
                }
            }
        }
        else{
            int k;
            cin>>k;
            v[k]=0;
        }
        
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}
