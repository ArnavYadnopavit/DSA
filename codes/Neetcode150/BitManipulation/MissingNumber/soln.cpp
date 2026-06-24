#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorsum=0;
        for(auto num:nums) xorsum^=num;
        for(int i=0;i<=nums.size();i++){
            xorsum^=i;
        }
        return xorsum;
    }
};
