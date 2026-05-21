#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l=0,sum=0,maxsum=INT_MIN;
        while(l<nums.size()){
            sum=0;
            while(sum>=0 && l<nums.size()){
                sum+=nums[l++];
                maxsum = max(sum,maxsum);
            }
        }
        return maxsum;

    }
};
