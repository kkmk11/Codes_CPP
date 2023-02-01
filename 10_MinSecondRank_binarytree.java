// In a Marketing Agency, each agent will mentor either two sub-agents,
// or zero agents. Now, based on ranks given to sub-agents, the mentor agent 
// will be ranked with the top rank among two sub-agents. 

// The ranks are in the range [1,20], More than one agent can have same rank.

// At the end, all mentor agents and sub agents, will be treated as agents only.

// You are given the entire ranking picture as a tree.
// Your task is to find out second top agent in the Marketing agency.
// If no such agent exist, return -2.

// Implement the class Solution:
//    1. public int findSecondTopAgent(BinaryTreeNode root): returns an integer.

// NOTE:
// 	- In the tree '-1', indicates empty(null).

// Input Format:
// -------------
// A single line of space separated integers, ranks of each individual.

// Output Format:
// --------------
// Print an integer, second top agent based on rank.


// Sample Input-1:
// ---------------
// 2 5 2 -1 -1 2 4

// Sample Output-1:
// ----------------
// 4


// Sample Input-2:
// ---------------
// 3 3 3 3 3

// Sample Output-2:
// ----------------
// -2

// ::For Tree structure refer to Hint::



solution1:
import java.util.*;
/*
class BinaryTreeNode{
	public int data; 
	public BinaryTreeNode left, right; 
	public BinaryTreeNode(int data){
		this.data = data; 
		left = null; 
		right = null; 
	}
}
*/
class Solution {
    static List<Integer> l=new ArrayList<>();
    static void inorder(BinaryTreeNode root){
        if(root!=null && root.data!=-1){
            inorder(root.left);
            if(!l.contains(root.data))
                l.add(root.data);
            inorder(root.right);
        }
    }
    public int findSecondTopAgent(BinaryTreeNode root) {
       //implement your code here.
       inorder(root);
        Collections.sort(l);
      if(l.size()>2){
          return l.get(1);
      }
       return -2;
    
    }
}



solution2:
import java.util.*;
/*
class BinaryTreeNode{
	public int data; 
	public BinaryTreeNode left, right; 
	public BinaryTreeNode(int data){
		this.data = data; 
		left = null; 
		right = null; 
	}
}
*/
class Solution {
    public int findSecondTopAgent(BinaryTreeNode root) {
       Queue<BinaryTreeNode> q=new LinkedList<>();
       q.add(root);
       ArrayList<Integer> l=new ArrayList<>();
       while(!q.isEmpty()){
           BinaryTreeNode front=q.peek();
           q.poll();
           if(!l.contains(front.data)){
               l.add(front.data);
           }
           if(front.left!=null && front.left.data!=-1){
               q.add(front.left);
           }
           if(front.right!=null && front.right.data!=-1){
               q.add(front.right);
           }
       }
       int mini1=212345;
       for(int i=0;i<l.size();i++){
           if(l.get(i)<mini1){
               mini1=l.get(i);
           }
       }
       int mini2=1234567;
       for(int i=0;i<l.size();i++){
