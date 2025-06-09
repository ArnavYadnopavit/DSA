#include <stdio.h>
#include <stdlib.h>

struct Array{
	int * A;
	int length;
	int size;
}typedef Array;

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

int main(){
	Array arr;
	arr.A=(int*)malloc(10*sizeof(int));
	arr.size=10;
	arr.length=0;
	Array* aptr=&arr;
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
}
