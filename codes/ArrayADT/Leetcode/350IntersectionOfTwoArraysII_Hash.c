/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int arr1[1001]={0},arr2[1001]={0};
    for(int i=0;i<nums1Size;i++){
        arr1[nums1[i]]++;
    }
    for(int i=0;i<nums2Size;i++){
        arr2[nums2[i]]++;
    }
    int total=0;
    for(int i=0;i<1001;i++){
        total+=(arr1[i]<arr2[i])?arr1[i]:arr2[i];

    }
    *returnSize=total;

    int* ret=(int*)malloc((*returnSize)*sizeof(int));
    int ptr=0;
    for(int i=0;i<1001;i++){
        int count=(arr1[i]<arr2[i])?arr1[i]:arr2[i];
        for(;count>0;count--){
            ret[ptr]= i;
            printf("%d",i);
            ptr++;
        }
    }
    return ret;
}
