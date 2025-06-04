#include <stdio.h>
int ncr(int n, int r){// ncr=n-1cr+n-1cr-1
	if (r==0||n==r){
		return 1;
	}
	else return ncr(n-1,r-1)+ncr(n-1,r);
}
int main(void){
	int n=5,r=3;
	printf("%d",ncr(n,r));
}
