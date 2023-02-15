// At university of Chicago a Computer Science programing faculty as a part of 
// teaching passion, in order to make newly joined students more enthusiastic 
// in learning the subject he will be giving a problem at the first day of semester.

// The student who tops they will be awarded with cash prize. In regard to this 
// he asked the students to work on concept related to strings, he gave a task to
// read a word and find the count of all the turn of phrases of the word, and 
// the phrases should be distinct.

// Now it’s time for you to create a method which satisfies the above program.
// A turn of phrases of a word is obtained by deleting 
// any number of characters (possibly zero) from the front of the word and
// any number of characters (possibly zero) from the back of the word.

// Input Format:
// -------------
// A single string, the word.

// Output Format:
// --------------
// Print an integer, number of distinct phrases possible.


// Sample Input-1:
// ---------------
// aabbaba

// Sample Output-1:
// ----------------
// 21

// Explanation:
// -------------
// The turn of phrases of the word, which are distinct as follows:
// a, b, aa, bb, ab, ba, aab, abb, bab, bba, aba, aabb, abba, bbab, baba, 
// aabba, abbab, bbaba, aabbab, abbaba, aabbaba


// Sample Input-2:
// ---------------
// kmithyd

// Sample Output-2:
// ----------------
// 28


#include<bits/stdc++.h>
using namespace std;
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
    int insert(string s){
        node *temp=head;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(temp->next[x]==NULL){
                temp->next[x]=new node();
            }
            temp=temp->next[x];
        }
        if(temp->word==true){
            return 0;
        }
        temp->word=true;
        return 1;
    }
    int search(string s){
        node *temp=head;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            if(temp->next[x]==NULL){
                return 0;
            }
            temp=temp->next[x];
        }
        return 1;
    }
};
int main(){
    Trie obj;
    int res=0;
    string s,k;
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            res=res+obj.insert(s.substr(i,j-i+1));
        }
    }
    cout<<res<<endl;
    cout<<"Enter a string to search : ";
    cin>>k;
    if(obj.search(k)==1){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}