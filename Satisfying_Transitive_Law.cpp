// A transitive law is "If a == b and b == c, then a == c"
// Which also says "If a == b and b != c, then a != c"

// You will be given a list of strings relations[], i.e, like p==q or p!=q.
// Your task is to find out whether all the relations follow the transitive law or not.
// If all of them followed return true, otherwise return false.

// Input Format:
// -------------
// Space separated strnigs, list of relations

// Output Format:
// --------------
// Print a boolean value, whether transitive law is obeyed or not.


// Sample Input-1:
// ---------------
// a==b c==d c!=e e==f

// Sample Output-1:
// ----------------
// true


// Sample Input-2:
// ---------------
// a==b b!=c c==a

// Sample Output-2:
// ----------------
// false


// Sample Input-3:
// ---------------
// a==b b==c c!=d d!=e f==g g!=d

// Sample Output-3:
// ----------------
// true





#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> nums;
    string s1,t1;
    getline(cin,s1);
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        nums.push_back(t1);
    }
    unordered_set<char> st;
    vector<char> v;
    unordered_map<char,vector<char>> m;
    unordered_map<char,vector<char>> nm;
    for(auto s:nums){
        if(s[1]=='!' && s[2]=='='){
            nm[s[0]].push_back(s[3]);
            nm[s[3]].push_back(s[0]);
        }
        else{
            m[s[0]].push_back(s[3]);
            m[s[3]].push_back(s[0]);
        }
        st.insert(s[0]);
        st.insert(s[3]);
    }
    for(auto i:st){
        v.push_back(i);
    }
    for(auto i:v){
        vector<bool> visited(26,false);
        vector<char> res;
        if(visited[i-'a']==false){
            queue<int> q;
            res.push_back(i);
            q.push(i);
            visited[i-'a']=true;
            while(!q.empty()){
                int front=q.front();
                q.pop();
                for(auto x:m[front]){
                    if(visited[x-'a']==false){
                        q.push(x);
                        res.push_back(x);
                        visited[x-'a']=true;
                    }
                }
            }
        }
        for(auto x:res){
            for(auto y:nm[i]){
                if(x==y){
                    cout<<"false";
                    exit(0);
                }
            }
        }
    }
    cout<<"true";
}
