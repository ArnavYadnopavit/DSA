#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmin=1;
        int curmax=1,res=nums[0];
        for(auto num:nums){
            int temp=curmax*num;
            curmax=max(num,max(num*curmax,num*curmin));
            curmin=min(num,min(temp,num*curmin));
            res =  max(res,curmax);
        }
        return res;
    }
};
