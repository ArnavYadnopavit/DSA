#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int i;//row
    int j;//col
    int x;//value
}element;

typedef struct sparse{
	int m;//total rows
	int n;//total cols
	int num;//number of non zero elements
	element* e;
}sparse;

void create(sparse *s,int m,int n,int num);
void display(sparse* s);
sparse* add(sparse *s1,sparse *s2);

#endif // MYLIB_H
