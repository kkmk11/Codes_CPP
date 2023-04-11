// In a joint family, every person assigned with an ID, an integer value.
// and the entire family is arranged in the from of tree.

// You will be given the family tree and two persons IDs P1 and P2.
// Your task is to find the person ID, who is the latest common ascendant of P1 and P2.
// and return the Lowest Common Ascendant ID.

// Implement the class Solution:
//     - Node lowestCommonAscendant(Node root, Node P1, Node P2):
//         return the person ID who is the latest common ascendant of P1 and P2.


// Input Format:
// -------------
// Line-1: Single line of space separated integers, person ID's in the family.
// Line-2: Two Person IDs, P1 and P2.

// Output Format:
// --------------
// Return the latest common ascendant of P1 and P2.


// Sample Input-1:
// ---------------
// 3 5 1 6 2 0 8 -1 -1 7 4
// 6 4

// Sample Output-1:
// ----------------
// 5

// Sample Input-2:
// ---------------
// 11 99 88 77 22 33 66 55 10 20 30 40 50 60 44
// 66 55

// Sample Output-2:
// ----------------
// 11





import java.util.*;

/*
//Sample Binary tree Node sturcture for reference 

class Node {
    public int data;
    public Node left;
    public Node right;
    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}
*/
class Solution {
    static int flag1=0,flag2=0;
    ArrayList<Node> l=new ArrayList<>();
    static void inorder(Node root,Node p1,Node p2){
        if(root==null){
            return;
        }
        inorder(root.left,p1,p2);
        if(root.data==p1.data){
            flag1=1;
        }
        if(root.data==p2.data){
            flag2=1;
        }
        inorder(root.right,p1,p2);
    }
    Node lowestCommonAscendant(Node root,Node P1, Node P2){
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            Node front=q.peek();
            q.poll();
            inorder(front,P1,P2);
            if(flag1==1 && flag2==1){
                l.add(front);
            }
            flag1=0;
            flag2=0;
            if(front.left!=null){
                q.add(front.left);
            }
            if(front.right!=null){
                q.add(front.right);
            }
        }
        return l.get(l.size()-1);
    }
}
