#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>
int slen(char* s);
void totheupper(char* s);
void tothelower(char* s);
int numofvowels1(char* s);
int numofvowels2(char* s);
int numofvowels3(char* s);
void StringValidation(char* s);
void Reverse(char* s);
void Duplicate(char* s);
void AnagramChecker(char* s1, char* s2);
void PermutationPrinter(char* s, int k);//while using function in main put k=0
void Permutation(char*s,int l,int h);
#endif // MYLIB_H

