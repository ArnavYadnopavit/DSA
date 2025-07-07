void reverse(int* left,int* right){
    int temp=0;
    for(int i=0;i<(right-left+1)/2;i++){
        temp=*(left+i);
        *(left+i)=*(right-i);
        *(right-i)=temp;
    }

}
/* This Logic Uses temp array which leads to
Space Complexity: O(n)
Time Complexity: O(n)
void rotate(int* nums, int numsSize, int k) {
    int rot=k%numsSize,temp[numsSize];
    for(int i=0;i<numsSize;i++){
        temp[(i+rot)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++){
        nums[i]=temp[i];
    }
}
*/
/*
This logic uses two pointers and reverse arrays at rot
Space Complexity: O(1)
Time Complexity: O(n)
*/
void rotate(int* nums, int numsSize, int k) {
    int rot=k%numsSize;
    reverse(nums,nums+numsSize-1);
    reverse(nums,nums+rot-1);
    reverse(nums+rot,nums+numsSize-1);    
}

