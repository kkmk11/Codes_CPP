// A wall clock is a complete whole circle and cover 360°.
// You are given the time as HH:MM.
// Your task is to return the angle between the Hours hand and Minutes hand
// of the clock and the angle should not be reflex angle.

// Input Format:
// -------------
// A string time, HH:MM

// Output Format:
// --------------
// Print a double result, within 10^-5 of the original value.


// Sample Input-1:
// ---------------
// 04:30

// Sample Output-1:
// ----------------
// 45.00000


// Sample Input-2:
// ---------------
// 06:15

// Sample Output-2:
// ----------------
// 97.50000




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int h=stoi(s.substr(0,2));   
    int m=stoi(s.substr(3,2));
    double hour_move=(double)h*30+(double)m*0.5;
    double min_move=((double)m/5.0)*30;
    double res=abs(hour_move-min_move);
    cout<<min(res,360-res);
}
