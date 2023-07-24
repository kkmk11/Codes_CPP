// Gopal would like to go on Tour, and planned a schedule.
// Airport authority has created a new way of issuing tickets.
// Gopal purchased a set of airline tickets, 
// each ticket contains the 'departure from' and 'arrival to'.

// Redesign the Gopal's tour schedule in an order.
// Gopal intially must begin his tour from BZA.
// Hence the tour schedule's start point should begin with BZA. 

// You are given a list of flight tickets which Gopal has purchased.
// Your task is to find out and return the tour schedule that has the least 
// lexical order. Gopal must use all the tickets once and only once.

// Note:
// ------
// If there are multiple valid schedules, you should return the schedule 
// that has the smallest lexical order when read as a single string. 
// For example, the schedule ["BZA", "LGA"] has a smaller lexical order than ["BZA", "LGB"].

// All airports are represented by three capital letters.
// You may assume all tickets form at least one valid schedule.

// Input Format:
// -------------
// Single Line of tickets separated by comma, and each ticket separated by space, 
// Gopal's flight tickets.

// Output Format:
// --------------
// Print the schedule, which is smallest lexical order of tour schedule.


// Sample Input-1:
// ----------------
// DEL HYD,BZA DEL,BLR MAA,HYD BLR

// Sample Output-1:
// --------------------
// [BZA, DEL, HYD, BLR, MAA]


// Sample Input-2:
// ------------------
// BZA BLR,BZA CCU,BLR CCU,CCU BZA,CCU BLR

// Sample Output-2:
// ------------------
// [BZA, BLR, CCU, BZA, CCU, BLR]




#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stringstream x1(s);
    string t1;
    map<string,set<string>> m;
    while(getline(x1,t1,',')){
        string a=t1.substr(0,3);
        string b=t1.substr(4,3);
        m[a].insert(b);
    }
    vector<string> res;
    stack<string> q;
    q.push("BZA");
    while(!q.empty()){
        string from=q.top();
        if(m[from].size()==0){
            res.push_back(from);
            q.pop();
        }
        else{
            auto to=m[from].begin(); //use only auto when retrieving some iterator value in cpp
            q.push(*to);
            m[from].erase(to);
        }
    }
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }
}
