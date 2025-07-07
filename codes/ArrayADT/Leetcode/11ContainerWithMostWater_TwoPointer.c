/*
Using Two Pointer
Time Complexity:O(n)
Space Compexity:O(1)
*/
int maxArea(int* height, int heightSize) {
    int left=0,right = heightSize-1,maxar=-1;
    while(left!=right){
        int high=(height[left]<height[right])?height[left]:height[right];
        int ar=(right-left)*high;
        maxar=(maxar<ar)?ar:maxar;
        if(height[left]<height[right]){
            left++;
        }
        else right--;
    }
    return maxar;
}
