#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int maxi=0;
    for(int i=0;i<n-k+1;i++){
        unordered_map<int,int> m;
        int s=0;
        for(int j=i;j<i+k;j++){
            s=s+v[j];
            m[v[j]]=m[v[j]]+1;
        }
        if(m.size()==k){
            maxi=max(maxi,s);
        }
        else{
            continue;
        }
    }
    cout<<maxi;
}
