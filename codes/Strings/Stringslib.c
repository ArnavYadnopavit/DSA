#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"  // include the header

int slen(char* s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}

void totheupper(char* s){
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>=97&&s[i]<=122){
			s[i]-=32;//lower case: a=65,z=90 and upper case: A=97,Z=122
		}
	}
}

void tothelower(char* s){
        for(int i=0;s[i]!='\0';i++){
                if(s[i]>=65&&s[i]<=90){
                        s[i]+=32;//lower case: A=65,Z=90 and upper case: a=97,z=122
                }       
        }
}

int numofvowels1(char* s){
	int count=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
			count++;
		}
	}
	return count;
}
int numofvowels2(char* s){
        int count=0;
        for(int i=0;s[i]!='\0';i++){
                if(s[i]=='a'){
                        count++;
                }
		else if(s[i]=='e'){
			count++;
		}
		else if(s[i]=='i'){
                        count++;
                }
		else if(s[i]=='o'){
                        count++;
                }
		else if(s[i]=='u'){
                        count++;
                }
		else if(s[i]=='A'){
                        count++;
                }
		else if(s[i]=='E'){
                        count++;
                }
		else if(s[i]=='I'){
                        count++;
                }
		else if(s[i]=='O'){
                        count++;
                }
		else if(s[i]=='U'){
                        count++;
                }
        }       
        return count;
}

int numofvowels3(char* s){//Fastest
    int count = 0;
    char lookup[256] = {0};
    lookup['a'] = lookup['e'] = lookup['i'] = lookup['o'] = lookup['u'] = 1;
    lookup['A'] = lookup['E'] = lookup['I'] = lookup['O'] = lookup['U'] = 1;

    for(int i = 0; s[i] != '\0'; i++){
        count += lookup[(unsigned char)s[i]];
    }
    return count;
}

void StringValidation(char* s){//Requirements: Only alphabets and numbers
	for(int i=0;s[i]!='\0';i++){
		if((s[i]>=30&&s[i]<=39)||(s[i]>=97&&s[i]<=122)||(s[i]>=65&&s[i]<=90)){
			continue;
		}
		else{
			printf("Invalid String\n");
			return;
		}
	}
	printf("Valid String\n");
}

void Reverse(char* s){
	int end=slen(s)-1;
	for(int i=0;i<end/2;i++){
		char temp=s[i];
		s[i]=s[end-i];
		s[end-i]=temp;
	}
}
void Duplicate(char* s){
	int hash[128]={0};
	for(int i=0;s[i]!='\0';i++){
		hash[s[i]]+=1;
	}
	for(int i=0;i<128;i++){
		if (hash[i]>1) printf("%c occurs %d times\n",i,hash[i]);
	}
}

void AnagramChecker(char* s1, char* s2){//Assuming only alphabets are present
	int hash[128]={0};
        for(int i=0;s1[i]!='\0';i++){
                hash[s1[i]]+=1;
        }
        for(int i=0;s2[i]!='\0';i++){
                hash[s2[i]]-=1;
        }
	for(int i=0;i<128;i++){
                if (hash[i]!=0) {
			printf("Not an Anagram");
			return;
		}
	}
	printf("Valid Anagram");
}

void PermutationPrinter(char* s, int k){//while using function in main put k=0
	static char res[10]={'\0'};
	static int A[10]={0};
	int i;
	if(s[k]=='\0'){
		res[k]='\0';
		printf("%s\n",res);
	}
	else{
		for(int i=0;s[i]!='\0';i++){
			if(A[i]==0){
				res[k]=s[i];
				A[i]=1;
				PermutationPrinter(s,k+1);
				A[i]=0;
			}
		}
	}
}
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void Permutation(char *s, int l, int h) {
    if (l == h) {
        printf("%s\n", s); // Only print when full permutation is ready
    } else {
        for (int i = l; i <= h; i++) {
            swap(&s[l], &s[i]);
            Permutation(s, l + 1, h);
            swap(&s[l], &s[i]); // backtrack
        }
    }
}


