// Malika taught a new fun time program practice for Engineering Students.
// As a part of this she has given set of N numbers, and asked the students 
// to perform the operations listed below:
// First, build the segment tree and then do the following,
//     1. sumRange(s1, s2) - return the sum of numbers between the indices 
//        s1 and s2, both are inclusive and 0<=s1<=s2<N.
//     2. update(ind, val) - update the value at the index 'ind' to 'val'.

// Your task is to solve this problem using Segment Tree concept.

// Input Format:
// -------------
// Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
// Line-2: N space separated integers.
// next Q lines: Three integers option, start/ind and end/val.

// Output Format:
// --------------
// An integer result, for every sumRange query.


// Sample Input:
// -------------
// 8 5
// 1 2 13 4 25 16 17 8
// 1 2 6		//sumRange
// 1 0 7		//sumRange
// 2 2 18	    //update
// 2 4 17	    //update
// 1 2 7		//sumRange

// Sample Output:
// --------------
// 75
// 86
// 80


import java.util.*;

public class Solution {
// Segment Tree Node structure
    class SegmentTreeNode {
        int start, end;
        SegmentTreeNode left, right;
        int sum;

        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    }
      
    SegmentTreeNode root = null;
   
    public Solution(int[] nums) {
        root = buildTree(nums, 0, nums.length-1);
    }

    private SegmentTreeNode buildTree(int[] nums, int start, int end) {
        //build the segment Tree
        SegmentTreeNode node =new SegmentTreeNode(start,end);
        if(start==end){
            node.sum=nums[start];
            return node;
        }
        int mid=start+(end-start)/2;
        node.left=buildTree(nums,start,mid);
        node.right=buildTree(nums,mid+1,end);
        node.sum=node.left.sum+node.right.sum;
        return node;
    }
   
    void update(int ind, int val) {
        updatehelper(ind,val,root);
        //implement update method
    }
    public int updatehelper(int ind,int val,SegmentTreeNode root){
        if(root==null){
            return 0;
        }
        int diff=0;
        if(root.start==ind && root.end==ind){
            diff=val-root.sum;
            root.sum=val;
            return diff;
        }
        if(ind>root.left.end){
            diff=updatehelper(ind,val,root.right);
        }
        else{
            diff=updatehelper(ind,val,root.left);
        }
        root.sum=root.sum+diff;
        return diff;
    }
    public int sumRange(int i, int j) {
        //implement sumRange method
        return sumhelper(i,j,root);
    }
    public int sumhelper(int i,int j,SegmentTreeNode root){
        if(root==null){
            return 0;
        }
        if(root.start==i && root.end==j){
            return root.sum;
        }
        if(i>root.left.end){
            return sumhelper(i,j,root.right);
        }
        else if(j<root.right.start){
            return sumhelper(i,j,root.left);
        }
        return sumhelper(i,root.left.end,root.left)+sumhelper(root.right.start,j,root.right);
    }
    
}
