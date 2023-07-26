// give an array example [1,2,4,3].
// here, u need to get the next greater element.
// if not return 1 for the position.

// input:
// [1,2,4,3]
// output:
// [2,4,-1,-1]


#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> res(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            res[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
