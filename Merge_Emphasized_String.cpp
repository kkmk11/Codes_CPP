// Reena has to sent the mails regularly.
// She used emphasize any word W based on a given set of words[].
// Two emphasize the words she used enclose them with <i> and </i> tag.
// The emphasize procedure of the sub-words of W is as follows:
	
// 	- If two sub-words are intersected with each other, 
// 	  enclose them with one <i></i> tag.
	
// 	- If two sub-words are enclosed with <i></i> tag and neighbours also,
// 	  then merge the sub-words as one and enclose with one <i> </i> tag.

// You will be given the word W, and set of words[] to emphasize.
// Your task is to help Reena to emphasize the word W.
// and print it.

// Input Format:
// -------------
// Line-1: A string W, the word.
// Line-2: space separated strings, set of words[].

// Output Format:
// --------------
// Print the string, the emphasized string.

// Sample Input-1:
// ---------------
// kmitngit123
// it 123

// Sample Output-1:
// ----------------
// km<i>it</i>ng<i>it123</i>


// Sample Input-2:
// ---------------
// qwertykeypad
// qwerty key pad

// Sample Output-2:
// ----------------
// <i>qwertykeypad</i>


// Sample Input-3:
// ---------------
//aaaabbbbbcccccccdddddddeeeeeeeefffffffffffff
// aaa ab bbc ccc cdd dee eff fff

// Sample Output-3:
// ----------------
// output =<i>aaaab</i>bb<i>bbcccccccdd</i>dddd<i>dee</i>eeeee<i>efffffffffffff</i>



#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<string> v;
    string s1;
    cin.ignore();
    getline(cin,s1);
    string t1;
    stringstream x1(s1);
    while(getline(x1,t1,' ')){
        v.push_back(t1);
    }
    
    //finding intervals
    vector<vector<int>> nums;
    for(auto x:v){
        for(int i=0;i<s.size()-x.size()+1;i++){
            if(s.substr(i,x.size())==x){
                vector<int> p;
                p.push_back(i);
                p.push_back(i+x.size()-1);
                nums.push_back(p);
            }
        }
    }
    
    //sorting intervals
    sort(nums.begin(),nums.end(),[&](vector<int> a,vector<int> b){
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
    
    //merging intervals
    vector<vector<int>> arr;
    if(nums.size()!=0){
        arr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]-arr.back()[1]<=1){
                arr.back()[0]=min(arr.back()[0],nums[i][0]);
                arr.back()[1]=max(arr.back()[1],nums[i][1]);
            }
            else{
                arr.push_back(nums[i]);
            }
        }
    }
    
    //finding result
    string res="";
    int prev=0;
    for(auto x:arr){
        string a="";
        if(x[0]!=0){
            a=s.substr(prev,x[0]-prev);
        }
        string b=s.substr(x[0],x[1]-x[0]+1);
        res=res+a+"<i>"+b+"</i>";
        prev=x[1]+1;
    }
    if(prev!=s.size()){
        res=res+s.substr(prev,s.size()-prev);
    }
    cout<<res;
}
