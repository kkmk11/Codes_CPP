// Kohinoor diamond is robbed by Hrithik, He kept the diamond in a suitcase, 
// the suitcase has a lock with 4 circular wheels, and each wheel consist of
// 0-9 digits in the order 0,1,2,3,4,5,6,7,8,9 only.
// You can rotate a wheel from 0 to 9 or 9 to 0.

// As the diamond is most valuable, the lock has some traps,
// if anybody try to unlock the suitcase and reached any one of the traps,
// the suitcase will be blasted. And you will be dead.

// Initially, the suitcase lock is set to 0000.
// and you will be given the unlock key, your task to find and print
// the minimum number of rotations required to unlock the suitcase.
// If it is not possible to unlock the suitcase without blasting, print -1.

// NOTE:
// In one rotation you can choose any one wheel and 
// rotate to its next or previous digit.


// Input Format:
// -------------
// Line-1: space separated strings, each string of length 4 and contains only digits [0-9]
// Line-2: A string, key to unlock.

// Output Format:
// --------------
// Print an integer, the minimum number of rotations required to unlock.


// Sample Input-1:
// ---------------
// 0302 0202 0203 2323 3003
// 0303 

// Sample Output-1:
// ----------------
// 8

// Explanation:
// ------------
// To unlock the suitcase the valid rotations are as follows:
// 0000 > 1000 > 1100 > 1200 > 1201 > 1202 > 1302 > 1303 > 0303.


// Sample Input-2:
// ---------------
// 6656 6676 6766 6566 5666 7666 6665 6667
// 6666 

// Sample Output-2:
// ----------------
// -1

// Explanation:
// ------------
// You can't unlock the suitcase.






#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string> traps;
    string s1;
    getline(cin,s1);
    stringstream x1(s1);
    string t1;
    while(getline(x1,t1,' ')){
        traps.insert(t1);
    }
    string target;
    cin>>target;
    
    set<string> visited;
    queue<string> q;
    if(traps.count("0000")==0){
        q.push("0000");
        visited.insert("0000");
    }
    else{
        cout<<-1;
        exit(0);
    }
    int c=1;
    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            string s=q.front();
            q.pop();
            if(s==target){
                cout<<c;
                exit(0);
            }
            for(int i=0;i<4;i++){
                string t1=s,t2=s;
                if(s[i]=='9'){
                    t1[i]='8';
                    t2[i]='0';
                }
                else if(s[i]=='0'){
                    t1[i]='9';
                    t2[i]='1';
                }
                else{
                    t1[i]=s[i]-1;
                    t2[i]=s[i]+1;
                }
                if(t1==target || t2==target){
                    cout<<c;
                    exit(0);
                }
                if(traps.count(t1)==0 && visited.count(t1)==0){
                    visited.insert(t1);
                    q.push(t1);
                }
                if(traps.count(t2)==0 && visited.count(t2)==0){
                    visited.insert(t2);
                    q.push(t2);
                }
            }
        }
        c++;
    }
    cout<<-1;
}
