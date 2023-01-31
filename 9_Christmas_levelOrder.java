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
