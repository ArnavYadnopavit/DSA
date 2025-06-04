#include <stdio.h>
int SumN(int n){
	if (n==0){
		return 0;
	}
	else return n+SumN(n-1);
}
int main(){
	int a;
	scanf("%d",&a);
	int sum=SumN(a);
	printf("%d",sum);
	return 0;
}
