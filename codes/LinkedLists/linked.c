#include <stdio.h>
#include <stdlib.h>
#include "hlinked.h"


int main(){
	int A[]={1,3,6,7,8,9};
	node* head=CreateFromArray(A,6);
	display(head);
	printf("%d\n",llen(head));
	printf("%d\n",sum(head));
	printf("%d\n",lmax(head));
	node* lin=LinearSearch(head,8);
	printf("%d\n",lin->x);
	insert(&head,3);
	insert(&head,3);
	display(head);
	delete(&head,10);
        display(head);
	RemoveDuplicates(&head);
	display(head);
	RecursiveReverse(&head,NULL,head);
	display(head);
        RecursiveReverse(&head,NULL,head);
	display(head);
	int B[]={0,2,4,5,7,10,11,15,16};
	node* head1=CreateFromArray(B,9);
	display(head1);
	node* mergedhead=Merge(head,head1);
	display(mergedhead);
	node* circ=CreateCircularFromArray(A,6);
	DisplayCircular(circ);
	InsertInCircular(&circ,5,6);
	DisplayCircular(circ);
	InsertInCircular(&circ,5,6);
	DisplayCircular(circ);
	DeleteFromCircular(&circ,5);
	DisplayCircular(circ);
}
