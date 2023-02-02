// For X-Mas, santa claus is preparing a X-Mas Tree with set of Bulbs.
// The bulbs are of different voltages, and preparation of tree as follows:
// 	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
// 	  so on.
// 	- At level-0: There will be only one bulb as root bulb.,
// 	- From next level onwards, we can attach atmost two bulbs to left side,
// 	  and right side of every bulb in previous level.
// 	- The empty attachements in a level are indicated with -1. 
// 	(for example: look in hint)
	
// Entire X-Mas tree has to be prepared with certian rules as follows:
// 	- For every even level in the X-Mas Tree, all the bulbs should have
// 	  odd voltages in strictly ascending order.
// 	- For every odd level in the X-Mas Tree, all the bulbs should have
// 	  even voltages in strictly descending order.
	
// You will be given the X-Mas Tree root,
// Your task is to findout whether the X-Mas tree is prepared as per the rules
// or not.

// Implement the class Solution.
// 1.public boolean isXmasTree(BinaryTreeNode root): returns a boolean value.


// Input Format:
// -------------
// A single line of space separated integers, voltages of the set of bulbs.

// Output Format:
// --------------
// Print a boolean value.



// Sample Input-1:
// ---------------
// 3 8 4 3 5 -1 7 

// Sample Output-1:
// ----------------
// true


// Sample Input-2:
// ---------------
// 3 8 4 3 5 7 7 

// Sample Output-2:
// ----------------
// false


// Sample Input-3:
// ---------------
// 1

// Sample Output-3:
// ----------------
// true
/*

/*
//TreeNode Structure for Your Reference..

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
import java.util.*;
class Solution {
    public boolean isXmasTree(BinaryTreeNode root) {
        // Implement Your Code here..
        Queue<BinaryTreeNode> q=new LinkedList<>();
        q.add(root);
        int level=0;
        while(!q.isEmpty()){
            List<Integer> l=new ArrayList<>();
            int c=q.size();
            while(c>0){
                BinaryTreeNode front=q.peek();
                l.add(front.data);
                q.poll();
                if(front.left!=null && front.left.data!=-1){
                    q.add(front.left);
                }
                if(front.right!=null && front.right.data!=-1){
                    q.add(front.right);
                }
                c--;
            }
            System.out.println(l);
            if(level%2!=0){
                // System.out.println(l);
                for(int i=0;i<l.size()-1;i++){
                    if(l.get(i)%2==0){
                        if(l.get(i)>l.get(i+1)){
                            continue;
                        }
                        else{
                            // System.out.println(false);
                            // System.exit(0);
                            return false;
                        }
                    }
                    else{
                        // System.out.println(false);
                        // System.exit(0);
                        return false;
                    }
                }
            }
            else if(level%2==0){
                // System.out.prin
                // tln(l);
                for(int i=0;i<l.size()-1;i++){
                    if(l.get(i)%2!=0){
                        if(l.get(i)<l.get(i+1)){
                            continue;
                        }
                        else{
                            // System.out.println(false);
                            // System.exit(0);
                            return false;
                        }
                    }
                    else{
                        // System.out.println(false);
                        // System.exit(0);
                        return false;
                    }
                }
            }
            l.clear();
            level++;
        }
        return true;
    }
}
