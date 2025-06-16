#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"  // include the header

void display(Array *arr){                //O(n)
	for(int i=0;i<arr->length;i++){
		printf("%d ",arr->A[i]);
	}
	printf("\n");
}
void add(Array *arr,int new){            //O(1)
	if (arr->size>arr->length){
		arr->A[arr->length]=new;
		arr->length++;
	}
	else printf("Array full\n");
}
void insert(Array *arr,int new,int index){//Best case O(1) Worst Case O(n)
        if (arr->size>arr->length){
		if(index<=arr->length){
		for(int i=arr->length;i>index;i--){
			arr->A[i]=arr->A[i-1];
		}
                arr->A[index]=new;
                arr->length++; 
		}
		else printf("Index out of bounds");
        }       
        else printf("Array full\n");
}
void delete(Array *arr,int index){//Best Case O(1) Worst Case O(n)
	if (arr->length==0){
		printf("Array Empty");
	}
	else if (index>arr->length-1) printf("Index out of bonds");
	else{
		for(int i=index;i<arr->length-1;i++){
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
	}
}
void swap(int* a,int* b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
int LinearSearch(Array* arr,int key){// TimeComplexity:O(n)
	int index=-1;
	for (int i=0;i<arr->length;i++){
		if (arr->A[i]==key) {
			index=i;
			break;
		}
	}
	//Following are improvements to Linear Search Commonly searched elements come forward
	//transposition swap(arr->A+index,arr->A+index-1)
	//MoveToFront   swap(arr->A+index,arr->A)

	return index;
}

int BinarySearch(Array* arr, int key){// TimeComlexity:O(log2(n)) But only works if the array is sorted
	int l=0,h=arr->length-1,mid;
	while(l<=h){
		mid=(l+h)/2;
		if (arr->A[mid]==key){
			return mid;
		}
		else if(arr->A[mid]>key){
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return -1;

}

int get(Array* arr, int index){
	if (index>=0&&index<arr->length) return arr->A[index];
}

void reset(Array* arr, int index,int a){
        if (index>=0&&index<arr->length) arr->A[index]=a;
        return;
}

int maxi(Array* arr){
	int ret=arr->A[0];
	for(int i=1;i<arr->length;i++){
		if(arr->A[i]>ret) ret=arr->A[i];
	}
	return ret;
}

int mini(Array* arr){
        int ret=arr->A[0];
        for(int i=1;i<arr->length;i++){
                if(arr->A[i]<ret) ret=arr->A[i];
        }
        return ret;
}
int summ(Array* arr){
        int ret=arr->A[0];
        for(int i=1;i<arr->length;i++){
                ret+=arr->A[i];
        }
        return ret;
}

double avgg(Array* arr){
	return (double)summ(arr)/arr->length;
}

void reverse(Array* arr){
	for (int i=0;i<arr->length/2;i++){
		swap(arr->A+i,arr->A+arr->length-i-1);
	}
}

void shift(Array* arr, int dir){//dir=1 for right shift , dir=-1 for left shift
	if (dir==1){
		for(int i=arr->length;i>0;i--){
			arr->A[i]=arr->A[i-1];
		}
		arr->A[0]=0;
	}
	else if(dir==-1){
                for(int i=0;arr->length-1<i;i++){
                        arr->A[i]=arr->A[i+1];
                }
                arr->A[arr->length-1]=0;
        }  
}

int mod(int a,int b){
	if(a>=0) return a%b;
	else return (b+a)%b; 
}

void rotate(Array* arr, int dir,int n){//dir=1 for right rotate , dir=-1 for left rotate, n is for rotate n times
        Array* ret=(Array*)malloc(sizeof(Array));
	ret->A=(int*)malloc(arr->size*sizeof(int));
        ret->size=arr->size;
	ret->length=arr->length;
	if (dir==1){
		for(int i=0;i<arr->length;i++){
			ret->A[i]=arr->A[(i+n)%arr->length];
		}
        }        
        else if(dir==-1){
		for(int i=arr->length;i>=0;i--){
                        ret->A[i]=arr->A[mod((i-n),arr->length)];
		}
	}
	free(arr->A);
	arr->A=ret->A;
	arr->length=ret->length;
	arr->size=ret->size;
}

Array* merge(Array* arr1,Array* arr2){
	//2,3,6,7,8
	//1,3,6,9,10
	//Can merge only 2 sorted lists
	Array* ret=(Array*)malloc(sizeof(Array));
	ret->A=(int*)malloc((arr1->size+arr2->size)*sizeof(int));
	ret->size=arr1->size+arr2->size;
        ret->length=arr1->length+arr2->length;
	int i=0,j=0,k=0;
	while(i<arr1->length&&j<arr2->length){
		if(arr1->A[i]>arr2->A[j]){
			ret->A[k]=arr2->A[j];
		        j++;
			k++;
		}
		else if(arr2->A[j]>arr1->A[i]){
                        ret->A[k]=arr1->A[i];
			i++;
			k++;
                }
		else{
			ret->A[k]=arr1->A[i];  
                        i++;k++;
			ret->A[k]=arr2->A[j];  
                        j++;k++;
		}
	}
    while (i < arr1->length) {
        ret->A[k++] = arr1->A[i++];
    }
    while (j < arr2->length) {
        ret->A[k++] = arr2->A[j++];
    }
    ret->length = k;
    return ret;
}

int FindSingleMissing(Array* arr){//Works only if array is sorted
	//1,2,4,5,6,7
	for (int i=0;i<arr->length;i++){
		if(arr->A[i]>arr->A[0]+i){
			return arr->A[i];
		}
	}
}

Array* FindMultipleMissingNotSorted(Array* arr){ //O(n)
	l=mini(arr);
	h=maxi(arr);
	int freq[h-l+1];//This is kind of a hash table
	for (int i=0;i<h-l+1;i++){
		freq[i]=0;
	}
	for(int i=0;i<arr->length;i++){
		freq[arr->A[i]]++;
	}
	Array* ret=(Array*)malloc(sizeof(Array));
        ret->A=(int*)malloc(arr->size*sizeof(int));
        ret->size=arr->size;
        ret->length=arr->length;

	for (int i=0;i<h-l+1;i++){
                if(freq[i]==0){
			printf("%d ",i);
			add(ret,i);
		}
        }
	return ret;
}

Array* FindMultipleMissing(Array* arr){
	Array* ret=(Array*)malloc(sizeof(Array));
        ret->A=(int*)malloc(arr->size*sizeof(int));
        ret->size=arr->size;
        ret->length=arr->length;
	//1,2,4,7,8,9,10
	//Method of difference btwn index and element
	int diff=arr->A[0];
	for(int i=1;i<arr->length;i++){
		if(diff!=arr->A[i]-i){
			while(diff<arr->A[i]-i){
				printf("%d ",diff+i);
				add(ret,diff+i);
				diff++;
			}
		}
	}
	return ret;
}

void FindingDuplicates(Array *arr){
	int lastDuplicate=0;
	for(int i=0;i<arr->length-1;i++){
		if(A[i]==A[i+1]&&A[i]!=lastDuplicate){
			printf("%d ",A[i]);
			lastDuplicate=A[i];
		}
	}
}

void 2sumHashing(Array * arr,int target){
	size=maxi(arr);
	int freq[size];
	for (int i=0;i<size;i++){
                freq[i]=0;
        }       
        for(int i=0;i<arr->length;i++){
		freq[arr->A[i]]++;
        }
	for(int i=0;i<size&&i<target+1;i++){
		if (freq[i]>0&&freq[target-i]>0){
			printf("%d and %d",i,target-i);
			return;
		}
	}
	return;
}
