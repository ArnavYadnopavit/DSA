#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size;
    int top;
    int* s;
}stack;

stack* CreateStack(int* A,int n,int size);
void Display(stack* st);
int pop(stack* st);
void push(stack* st,int x);
int peek(stack* st,int index);
int peek(stack* st,int index);

#endif // MYLIB_H