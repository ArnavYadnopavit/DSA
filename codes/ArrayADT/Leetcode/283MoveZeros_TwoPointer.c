void swap(int* a,int * b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
//left will lock onto 0
//right will be on non zero element
//Uses Two Pointer
//Time Complexity: O(n)
//Space Complexity: O(1) (Not COunting Input Array)
void moveZeroes(int* nums, int numsSize) {
    int *left=nums,*right=nums;
    while(right<=nums+numsSize-1&&left<=right){
        if(*left!=0){
            if(left==right)right++;
            left++;
            
        }
        else if(*right==0||left==right){
            right++;
        }
        else if(*left==0&&*right!=0){
            swap(left,right);
        }
    }


}
