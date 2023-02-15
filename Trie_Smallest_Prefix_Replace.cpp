// In an english training institute, the trainer Reeta given a task to the trainees.
// We know that, in english we have prefixes and suffixes for the words.
// You can divide a word as concatenation of prefix and suffix.
// i.e., word = prefix + suffix, another = an + other

// You will be given a list of prefixes and a statement consisting of words.
// Now, the task given to the trainees is as follows:
// 	- Replace all the words in the statement with the prefix, 
// 	  if you found prefix of that word in the list.
// 	- If you found more than one prefix in the list for a word in the statement,
// 	  replace the word with the prefix that has the shortest length.

// Your task is to help the trainees to prepare and print the final statement
// after all the replacements done.

// Input Format:
// -------------
// Line-1: Space separated strings, prefixes.
// Line-2: A single line of words, statement.

// Output Format:
// --------------
// Print the String, the final statement.


// Sample Input-1:
// ---------------
// am add mean ref 
// amigos used to address or refer to a friend

// Sample Output-1:
// ----------------
// am used to add or ref to a friend


// Sample Input-2:
// ---------------
// th the pa tho
// thomas the trainer teaches theroy part of thermodynamics

// Sample Output-2:
// ----------------
// th th trainer teaches th pa of th



// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1,t1;
//     getline(cin,s1);
//     stringstream x1(s1);
//     vector<string> v1;
//     while(getline(x1,t1,' ')){
//         v1.push_back(t1);
//     }
//     string s2,t2;
//     getline(cin,s2);
//     stringstream x2(s2);
//     vector<string> v2;
//     while(getline(x2,t2,' ')){
//         v2.push_back(t2);
//     }
//     vector<string> res;
//     for(string s:v2){
//         string x=s;
//         for(string a:v1){
//             if(s.substr(0,a.size())==a){
//                 if(x.size()>a.size()){
//                     x=a;
//                 }
//             }
//         }
//         res.push_back(x);
//     }
//     for(string i:res){
//         cout<<i<<" ";
//     }
// }

#include<bits/stdc++.h>
using namespace std;
vector<string> res;
class node{
    public:
    node *next[26];
    bool word;
    node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        word=false;
    }
};
class Trie{
    public:
    node *head=new node();
    void insert(string s){
        node *temp=head;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(temp->next[x]==NULL){
                temp->next[x]=new node();
            }
            temp=temp->next[x];
        }
        temp->word=true;
    }
    int search(string s){
        node *temp=head;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(temp->next[x]!=NULL){
                temp=temp->next[x];
            }
            else{
                return -1;
            }
        }
        return 1;
    }
    
};
int main(){
    string s1,t1;
    getline(cin,s1);
    stringstream x1(s1);
    vector<string> v1;
    while(getline(x1,t1,' ')){
        v1.push_back(t1);
    }
    string s2,t2;
    getline(cin,s2);
    stringstream x2(s2);
    vector<string> v2;
    while(getline(x2,t2,' ')){
        v2.push_back(t2);
    }
    for(string s:v2){
        Trie obj;
        obj.insert(s);
        string m=s;
        for(string k:v1){
            if(obj.search(k)==1){
                if(k.size()<m.size()){
                    m=k;
                }
            }
        }
        res.push_back(m);
    }
    for(string s:res){
        cout<<s<<" ";
    }
}
