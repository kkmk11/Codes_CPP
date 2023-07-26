// Given r red, b blue, and g green balls, find the total number of arrangements in a row such that no two balls of the same color end up together.
// input format : three integers (first integer is for r second is b and last is for g)
// output format : integer number

// Input:1  2 1
// Output: 6
// The arrangements are [bgbr, bgrb, brbg, brgb, gbrb, rbgb]
// Input:  2 3 1
 
// Output:10
 
// The arrangements are [bgbrbr, bgrbrb, brbgbr, brbgrb, brbrbg, brbrgb, brgbrb, gbrbrb, rbgbrb, rbrbgb]



#include<bits/stdc++.h>
using namespace std;
int solve(string x,int r,int b,int g){
    if(r==0 && b==0 && g==0){
        return 1;
    }
    int c=0;
    if(x.size()==0){
        if(r!=0){
            c=c+solve(x+'r',r-1,b,g);
        }
        if(b!=0){
            c=c+solve(x+'b',r,b-1,g);
        }
        if(g!=0){
            c=c+solve(x+'g',r,b,g-1);
        }
    }
    else{
        if(x.back()!='r' && r!=0){
            c=c+solve(x+'r',r-1,b,g);
        }
        if(x.back()!='b' && b!=0){
            c=c+solve(x+'b',r,b-1,g);
        }
        if(x.back()!='g' && g!=0){
            c=c+solve(x+'g',r,b,g-1);
        }
    }
    return c;
}
int main(){
    int r,b,g;
    cin>>r>>b>>g;
    string x="";
    cout<<solve(x,r,b,g);
}
