// For X-Mas, santa claus is preparing a X-Mas Tree with set of Bulbs.
// The bulbs are of different voltages, and preparation of tree as follows:
// 	- The bulbs are arranged in level-wise, levels are numbered from 0,1,2,3..
// 	  so on.
// 	- At level-0: There will be only one bulb as root bulb.,
// 	- From next level onwards, we can attach atmost two bulbs to left side,
// 	  and right side of every bulb in previous level.
// 	- The empty attachements in each level are indicated with null. 
// 	(for example: look in hint)

// You will be given the root of the X-Mas Tree,
// Your task is to findout the bulb with highest voltage in each level.

// Implement the class Solution:
// 1.public List<Integer> maxInEachRow(BinaryTreeNode root): returns the list of integers.


// Input Format:
// -------------
// A single line of space separated integers, voltages of the set of bulbs.

// Output Format:
// --------------
// Print the list of voltages.


// Sample Input-1:
// ---------------
// 2 4 3 6 4 -1 9

// Sample Output-1:
// ----------------
// [2, 4, 9]


// Sample Input-2:
// ---------------
// 3 4 7 7 3 8 4 

// Sample Output-2:
// ----------------
// [3, 4, 8]
// // 



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
    public List<Integer> maxInEachRow(Node root) {
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        List<Integer> l=new ArrayList<>();
        while(!q.isEmpty()){
            int c=q.size();
            int maxi=Integer.MIN_VALUE;
            while(c>0){
                Node front=q.peek();
                q.poll();
                if(maxi<front.data){
                    maxi=front.data;
                }
                if(front.left!=null){
                    q.add(front.left);
                }
                if(front.right!=null){
                    q.add(front.right);
                }
                c--;
            }
            l.add(maxi);
        }
        return l;
    }
}
