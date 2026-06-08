#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;
        for(int i=1;i<nums.size();i++){
            int temp = max(rob1+nums[i],rob2);
            rob1= rob2;
            rob2 = temp;
        }
        int arob1 = 0;
        int arob2 = 0;
        for(int i=0;i<nums.size()-1;i++){
            int atemp = max(arob1+nums[i],arob2);
            arob1= arob2;
            arob2 = atemp;
        }
        return max(nums[0],max(rob2,arob2));
    }
};
