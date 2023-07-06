// Alien Dictionary
// HardAccuracy: 47.81%Submissions: 70K+Points: 8
// Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Example 2:

// Input: 
// N = 3, K = 3
// dict = {"caa","aaa","aab"}
// Output:
// 1
// Explanation:
// Here order of characters is
// 'c', 'a', 'b' Note that words are sorted
// and in the given language "caa" comes before
// "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


// Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
// Expected Space Compelxity: O(K)


// Constraints:
// 1 ≤ N, M ≤ 300
// 1 ≤ K ≤ 26
// 1 ≤ Length of words ≤ 50



class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        set<vector<char>> s;
        for(int i=0;i<n-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            int x=0;
            while(x<a.size() && x<b.size()){
                if(a[x]!=b[x]){
                    s.insert({a[x],b[x]});
                    break;
                }
                x++;
            }
        }
        unordered_map<int,vector<int>> m;
        for(auto i:s){
            m[i[0]-'a'].push_back(i[1]-'a');
        }
        vector<int> indg(k,0);
        for(int i=0;i<k;i++){
            for(int j:m[i]){
                indg[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<k;i++){
            if(indg[i]==0){
                q.push(i);
            }
        }
        string res="";
        while(!q.empty()){
            int front=q.front();
            q.pop();
            res=res+char(97+front);
            for(auto i:m[front]){
                indg[i]--;
                if(indg[i]==0){
                    q.push(i);
                }
            }
        }
        return res;
    }
};
