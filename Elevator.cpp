// In Dubai's Burj Khalifa, there is an elevator moves only in upwards direction, 
// the elevator can carry N members.

// The people are waiting for the elevator at different floors, made P requests, 
// request[i] = [ num_people, enter_floor, exit_floor ], each request indicates, 
// number of people to enter into elevator, entering floor number, 
// exiting floor number.

// Initially the elevator is empty.

// Your task is to find and return true, iff it is possible to enter the people
// into elevator and exit from elevator of all the requests made by the people.


// Input Format:
// -------------
// Line-1 -> Two integers P and N, number of requests and number of members 
//           can be carried by elevator.
// Next N Lines -> three space separated integers, num_people, enter_floor, exit_floor.

// Output Format:
// --------------
// Print a boolean value.


// Sample Input-1:
// ---------------
// 2 5
// 2 1 5
// 3 3 7

// Sample Output-1:
// ----------------
// true



// Sample Input-2:
// ---------------
// 2 4
// 2 1 5
// 3 3 7

// Sample Output-2:
// ----------------
// false



// Sample Input-3:
// ---------------
// 3 11
// 3 2 7
// 3 7 9
// 8 3 9

// Sample Output-3:
// ----------------
// true



#include<bits/stdc++.h>
using namespace std;
int main(){
    int op,cap;
    cin>>op>>cap;
    vector<vector<int>> v(op,vector<int> (3,0));
    for(int i=0;i<op;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    vector<int> arr(51,0);
    for(auto x:v){
        arr[x[1]]=arr[x[1]]+x[0];
        arr[x[2]]=arr[x[2]]-x[0];
    }
    for(int i:arr){
        cap=cap-i;
        if(cap<0){
            cout<<"false";
            exit(0);
        }
    }
    cout<<"true";
}
