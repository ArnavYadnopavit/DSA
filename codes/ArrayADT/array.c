#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h" 

int main(){
	Array *aptr=(Array*)malloc(sizeof(Array));
	aptr->A=(int*)malloc(10*sizeof(int));
	aptr->size=10;
	aptr->length=0;
	add(aptr,1);
        add(aptr,2);
        add(aptr,3);
        add(aptr,4);
        add(aptr,5);
        add(aptr,7);
        add(aptr,8);
        add(aptr,10);
	display(aptr);
	insert(aptr,6,5);
	display(aptr);
	insert(aptr,9,8);
	display(aptr);
        add(aptr,1);
	printf("%d\n",LinearSearch(aptr,1));
	printf("%d\n",BinarySearch(aptr,1));
	delete(aptr,0);
	display(aptr);
	add(aptr,11);
	display(aptr);
	printf("%d\n",LinearSearch(aptr,1));
        printf("%d\n",BinarySearch(aptr,1));
	printf("%d\n",get(aptr,9));
	reset(aptr,9,12);
	display(aptr);
	printf("Max=%d, Min=%d, Sum=%d, Avg=%lf\n",maxi(aptr),mini(aptr),summ(aptr),avgg(aptr));
	/*shift(aptr,1);
	display(aptr);
	shift(aptr,-1);
	display(aptr);*/
	rotate(aptr,1,15);
	display(aptr);
	rotate(aptr,-1,5);

	display(aptr);
	
	Array *aptr2=(Array*)malloc(sizeof(Array));
        aptr2->A=(int*)malloc(10*sizeof(int));
        aptr2->size=10;
        aptr2->length=0;
        add(aptr2,1);
        add(aptr2,2);
        add(aptr2,3);
        add(aptr2,4);
        add(aptr2,5);
	display(aptr2);
	Array* merged=merge(aptr,aptr2);
	display(merged);
	free(aptr->A);
free(aptr);
free(aptr2->A);
free(aptr2);

}
