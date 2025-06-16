#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *A;
    int length;
    int size;
} Array;

void display(Array *arr);
void add(Array *arr,int new);
void insert(Array *arr,int new,int index);
void delete(Array *arr,int index);
void swap(int* a,int* b);
int LinearSearch(Array* arr,int key);
int BinarySearch(Array* arr, int key);
int get(Array* arr, int index);
void reset(Array* arr, int index,int a);
int maxi(Array* arr);
int mini(Array* arr);
int summ(Array* arr);
double avgg(Array* arr);
void reverse(Array* arr);
void shift(Array* arr, int dir);
int mod(int a,int b);
void rotate(Array* arr, int dir,int n);
Array* merge(Array* arr1,Array* arr2);

#endif // MYLIB_H

