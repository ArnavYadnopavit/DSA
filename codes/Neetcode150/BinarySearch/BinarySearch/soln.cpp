#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size(),ptr;
        while(l<r){
            ptr=l + (r-l-1)/2;
            if(nums[ptr]==target) return ptr;
            else if(nums[ptr]>target) r=ptr;
            else l=ptr+1;
        }
        return -1;

    }
};
