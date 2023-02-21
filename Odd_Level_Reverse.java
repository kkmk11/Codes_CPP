// For X-Mas, santa claus is preparing a X-Mas Tree with set of Bulbs.
// The bulbs are of different voltages, and preparation of tree as follows:
// 	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
// 	  so on.
// 	- At level-0: There will be only one bulb as root bulb.,
// 	- From next level onwards, we have to attach two bulbs to left side,
// 	  and right side of every bulb in previous level.
// 	- At each level, there must be two bulbs attached to its previous level bulbs.
// 	- After the last level, there will be noe more bulbs attached.

// You will be given the root of the X-Mas Tree (i.e.,perfect binary tree),
// Your task is to return the root of the structure, after you reverse the bulbs
// arrangement at ODD levels. 

// Implement the class Solution:
// 1.public Node reverseValuesInOddLevel(Node root): returns the list of integers.


// Input Format:
// -------------
// An integer, number of bulbs.
// A single line of space separated integers, voltages of the set of N bulbs.

// Output Format:
// --------------
// Print the list of voltages of the bulbs from the root.


// Sample Input-1:
// ---------------
// 7
// 1 2 3 4 5 6 7

// Sample Output-1:
// ----------------
// 1 3 2 4 5 6 7


// Sample Input-2:
// ---------------
// 15
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

// Sample Output-2:
// ----------------
// 1 3 2 4 5 6 7 15 14 13 12 11 10 9 8






/*
//TreeNode Structure for Your Reference..

class Node{
	public int data; 
	public Node left, right; 
	public Node(int data){
		this.data = data; 
		left = null; 
		right = null; 
	}
}

*/
import java.util.*;
class Solution {
    public Node reverseValuesInOddLevel(Node root) {
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        int level=0;
        while(!q.isEmpty()){
            ArrayList<Integer> l=new ArrayList<>();
            int k=q.size(),p=q.size();
            while(k>0){
                Node front=q.peek();
                q.poll();
                l.add(front.data);
                k--;
                q.add(front);
            }
            if(level%2!=0){
                int x=l.size()-1;
                while(p>0){
                    Node front=q.peek();
                    q.poll();
                    front.data=l.get(x);
                    if(front.left!=null){
                        q.add(front.left);
                    }
                    if(front.right!=null){
                        q.add(front.right);
                    }
                    p--;
                    x--;
                }
            }
            else{
                while(p>0){
                    Node front=q.peek();
                    q.poll();
                    if(front.left!=null){
                        q.add(front.left);
                    }
                    if(front.right!=null){
                        q.add(front.right);
                    }
                    p--;
                }
            }
            level++;
        }
        return root;
    }
}
