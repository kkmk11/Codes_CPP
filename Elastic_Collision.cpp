// AnnaMike loves Physics! Recently, he learned about Elastic Collisions. A perfectly 
// elastic collision is the one where the total momentum of the colliding bodies does
// not change after the collision. A very important property of elastic collisions, 
// that AnnaMike observed is that, if the 2 colliding bodies have equal masses, their 
// velocities will be exchanged after the collision.

// AnnaMike decided to conduct an experiment to demonstrate this property. 
// He bought N balls, all having equal masses, and a long board having length L 
// (in meters). He placed the balls at different positions on the board, placing 
// the ith ball at a distance of Ai, measured from the left end (in meters).

// At time t=0, he gave different velocities to each of the balls. The ith ball 
// received a velocity equal to Vi (in meters per second). (Vi ≠ 0, for any i). 
// A negative velocity indicates that the ball was pushed to the left, while a 
// positive velocity is the one that is directed towards right.

// AnnaMike was immensely happy to see the large number of collisions that happened 
// on the board. But, the balls soon started to fall off the board (from both the ends), 
// and finally there was no ball left. He is now interested to know : At what time 
// did the last ball fall? Will you help him?

// NOTE:
// -----
// - A ball will fall off the board when it is moving towards left and reaches x = 0, 
// or when it is moving towards right and reaches x = L. 
// (x is measured from the left end of the board)

// - It is guaranteed that eventually all the balls will fall off the board.

// Input Format:
// -------------
// Line-1: Two space separated integers N,L, number of balls and length
// Line-2: N space seprated integers, positions of balls
// Line-3: Direction of balls left(-1) or right(1)

// Output Format:
// -------------
// An integer output


// Sample Input-1:
// ---------------
// 4 4
// 0 1 3 4
// 1 1 -1 -1

// Sample Output-1:
// ----------------
// 4


// Sample Input-2:
// ---------------
// 4 6
// 2 3 4 5
// 1 -1 1 -1

// Sample Output-2:
// ----------------
// 5





#include<bits/stdc++.h>
using namespace std;
int main(){
    int maxi=0;
    int balls,length;
    cin>>balls>>length;
    vector<int> a(balls,0);
    for(int i=0;i<balls;i++){
        cin>>a[i];
    }
    vector<int> b(balls,0);
    for(int i=0;i<balls;i++){
        cin>>b[i];
    }
    for(int i=0;i<balls;i++){
        int l=a[i]/abs(b[i]);
        int r=((length-a[i])/abs(b[i]));
        if(b[i]<0){
            maxi=max(maxi,l);
        }
        else{
            maxi=max(maxi,r);
        }
    }
    cout<<maxi;
}
