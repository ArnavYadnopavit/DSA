#include <stdio.h>
#include <stdlib.h>
#include "Sparse.h" 


int main(){
	int m1=5,n1=5,num1=5,m2=5,n2=5,num2=7;
	sparse s1,s2;
	create(&s1,m1,n1,num1);
	create(&s2,m2,n2,num2);
	display(&s1);
	display(&s2);
	sparse *addd=add(&s1,&s2);
	display(addd);
}
