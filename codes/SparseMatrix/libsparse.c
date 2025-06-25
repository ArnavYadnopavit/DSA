#include <stdio.h>
#include <stdlib.h>
#include "Sparse.h"  // include the header

void create(sparse *s,int m,int n,int num){
	s->m=m;
	s->n=n;
	s->num=num;
	s->e=(element*)malloc(s->num*sizeof(element));
	printf("Enter Values\n");
	for(int i=0;i<s->num;i++){
		printf("Element %d\n",i+1);
		scanf("%d %d %d", &s->e[i].i,&s->e[i].j,&s->e[i].x); // row
	}
}

void display(sparse* s){
	int k=0;
	for(int i=0;i<s->m;i++){
		for(int j=0;j<s->n;j++){
			if(i==s->e[k].i && j==s->e[k].j){
				printf("%d ",s->e[k++].x);
			}
			else printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

sparse* add(sparse *s1,sparse *s2){
	sparse* ret=(sparse*)malloc(sizeof(sparse));
	ret->m=s1->m;
	ret->n=s1->n;
	ret->num=s1->num+s2->num;
	ret->e=(element*)malloc(ret->num*sizeof(element));
	int k=0,i=0,j=0;
	while(i<s1->num&&j<s2->num){
		if(s1->e[i].i<s2->e[i].i) ret->e[k++]=s1->e[i++];
		else if(s1->e[i].i>s2->e[j].i) ret->e[k++]=s2->e[j++];
		else if(s1->e[i].j<s2->e[j].j)ret->e[k++]=s1->e[i++];
		else if(s1->e[i].j>s2->e[i].j)ret->e[k++]=s2->e[j++];
		else {
			ret->e[k]=s1->e[i];
			ret->e[k++].x=s1->e[i++].x+s2->e[j++].x;
		}
	}
	 while(i<s1->num){
		 ret->e[k++]=s1->e[i++];
	 }
	  while(j<s2->num){
                 ret->e[k++]=s2->e[j++];
         }
	  return ret;
}

