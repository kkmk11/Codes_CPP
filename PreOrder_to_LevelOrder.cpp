// Given a preorder traversal of a tree as an array of integers arr[].
// Construct a binary search tree for the above tree.

// Note: 
//     A binary search tree is a binary tree where for every node, any 
//     descendant of Node.left has a value strictly less than Node.val, and 
//     any descendant of Node.right has a value strictly greater than Node.val.
     
//     A preorder traversal of a binary tree displays the value of the node first, 
//     then traverses Node.left, then traverses Node.right.

// Your task is to print the level order traversal of binary search tree that
// has been constructed using the pre order values of a binary tree.
// In the output, all null nodes in the level order traversal are indicated with -1. 

// Input Format:
// -------------
// Line-1: Size of array n
// Line-2: Array elements of size n.

// Output Format:
// --------------
// Print the level order traversal


// Sample Input-1:
// ---------------
// 6
// 10 6 2 8 12 16

// Sample Output-1:
// ----------------
// 10 6 12 2 8 -1 16


// Sample Input-2:
// ---------------
// 3 5

// Sample Output-2:
// ----------------
// 3 -1 5


#include<bits/stdc++.h>
using namespace std;
vector<int> v;
class TreeNode{
    public:
    int val;
    TreeNode *left,*right;
    TreeNode(int d){
        val=d;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    TreeNode *root;
    BST(){
        root=NULL;
    }
    TreeNode* addTreeNode(TreeNode *root,int d){
        if(root==NULL){
            TreeNode *nn=new TreeNode(d);
            return nn;
        }
        else if(root->val>d){
            root->left=addTreeNode(root->left,d);
            return root;
        }
        else{
            root->right=addTreeNode(root->right,d);
            return root;
        }
    }
    void lot(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *front=q.front();
            q.pop();
            if(front->val==-1){
                v.push_back(-1);
            }
            else{
                v.push_back(front->val);
                if(front->left!=NULL && front->left->val!=-1){
                    q.push(front->left);
                }
                else{
                    q.push(new TreeNode(-1));
                }
                if(front->right!=NULL && front->right->val!=-1){
                    q.push(front->right);
                }
                else{
                    q.push(new TreeNode(-1));
                }
            }
        }
    }
};
int main(){
    BST obj;
    int n;
    cin>>n;
    TreeNode *t;
    for(int i=0;i<n;i++){
        if(i==0){
            int x;
            cin>>x;
            t=obj.addTreeNode(NULL,x); 
        }
        else{
            int x;
            cin>>x;
            t=obj.addTreeNode(t,x);
        }
    }
    
    obj.lot(t);
    int p=0;
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]!=-1){
            p=i;
            break;
        }
    }
    for(int i=0;i<=p;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
