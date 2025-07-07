#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;//data
    struct node* next;//ptr
}node;

typedef struct doublenode{
	int x;//data
	struct doublenode* next;//next
	struct doublenode* prev;//prev
}doublenode;

typedef struct DoubleLinkedList{
	doublenode* head;
	doublenode* tail;
	int len;
}

node* NewNode(int x);
node* CreateFromArray(int* A,int n);
void display(node* linked);
int llen(node* head);
int sum(node* head);
int lmax(node* head);
node* LinearSearch(node* head,int key);
void insert(node** head,int key);
void delete(node** head,int key);
void RemoveDuplicates(node** head);
void Reverse(node** head);
void RecursiveReverse(node** head,node* q,node* p);
node* Merge(node* head1,node* head2);
int IsLoop(node* head);
node* CreateCircularFromArray(int* A,int n);
void DisplayCircular(node* head);
void InsertInCircular(node** head,int value,int index);
void DeleteFromCircular(node** head,int key);

#endif // MYLIB_H
