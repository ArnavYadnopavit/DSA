#include <stdio.h>
#include <stdlib.h>

void merge(int* arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int A1[n1],A2[n2];
    for(int i=left;i<left+n1;i++){
        A1[i-left]=arr[i];
    }
    for(int i=mid+1;i<mid+1+n2;i++){
        A2[i-mid-1]=arr[i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(A1[i]<A2[j]){
            arr[k++]=A1[i++];
        }
        else if(A1[i]>A2[j]){
            arr[k++]=A2[j++];
        }
        else{
            arr[k++]=A1[i++];
            arr[k++]=A2[j++];
        }
    }
    while(i<n1){
        arr[k++]=A1[i++];
    }
    while(j<n1){
        arr[k++]=A2[j++];
    }
}

void mergeSort(int* arr,int left,int right){
    if(left<right){
        int mid=(right+left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main() {
    int arr[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}