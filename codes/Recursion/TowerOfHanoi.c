#include <stdio.h>

/*
 The way Tower of Hanoi works in you have 3 pillars A,B,C which we will we number here as 1,2,3
 There are n discs arrange in order on A such that smallest disc is on top and largest is on bottom and we have to move all the discs to C. But there are 2 Rules
 
 1) You can move only 1 disc at one time
 2) You can only keep a smaller disc on a bigger disc
 
 Start by analysing smaller cases
 1) 1 disc TowerOfHanoi(1,A,B,C)
 move disc from A to C using B
 2)2 disc TowerOfHanoi(2,A,B,C)
 TowerofHanoi(1,A,C,B)
 move disc from A to C using B
 TowerOfHanoi(1,B,A,C)
 3)3 disc TowerOfHanoi(3,A,B,C)
 TowerOfHanoi(2,A,C,B)
 move disc from A to C using B
 TowerOfHanoi(3,B,A,C)
 n)n disc TowerOfHanoi(n,A,B,C)
 TowerOfHanoi(n-1,A,C,B)
 move disc from A to C using B
 TowerOfHanoi(n-1,B,A,C)

 Basically for n discs somehow get n-1 discs to B, then get nth disc to C then get the n-1 disc to C
*/

void TowerOfHanoi(int n,int A,int B,int C){
	if (n==0) return;
	TowerOfHanoi(n-1,A,C,B);
	printf("Move disc on %c to %c\n", 64+A,64+C);
	TowerOfHanoi(n-1,B,A,C);
}

int main(void){
	TowerOfHanoi(4,1,2,3);
}

