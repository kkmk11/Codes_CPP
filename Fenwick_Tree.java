// Malika taught a new fun time program practice for Engineering Students.
// As a part of this she has given set of N numbers, and asked the students 
// to perform the operations listed below:
// First, build the Binary Indexed Tree and then do the following,
//     1. sumRange(s1, s2) - return the sum of numbers between the indices 
//        s1 and s2, both are inclusive and 0<=s1<=s2<N.
//     2. update(ind, val) - update the value at the index 'ind' to 'val'.

// Your task is to solve this problem using Binary Indexed Tree concept.

// Input Format:
// -------------
// Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
// Line-2: N space separated integers.
// Next Q lines: Three integers option, start/ind and end/val.

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
    public int[] nums;
    public int[] bit;
    public int n;
    public Solution(int[] nums){
        this.nums=nums;
        n=nums.length;
        bit=new int[n+1];
        for(int i=0;i<n;i++){
            build(i,nums[i]);
        }
    }
    void build(int ind,int val){
        ind=ind+1;
        while(ind<=n){
            bit[ind]+=val;
            ind+=ind&(-ind);
        }
    }
    void update(int ind, int val) {
        //implement update method
        int diff=val-nums[ind];
        nums[ind]=val;
        ind+=1;
        while(ind<=n){
            bit[ind]+=diff;
            ind+=ind&(-ind);
        }
    }
    
    public int sumRange(int i, int j) {
        //implement sumRange method
        int sum2=0;
        j=j+1;
        while(j>0){
            sum2+=bit[j];
            j-=j&(-j);
            
        }
        int sum1=0;
        while(i>0){
            sum1+=bit[i];
            i-=i&(-i);
        }
        return sum2-sum1;
    }
}
