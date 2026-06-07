#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;
        for(auto num:nums){
            int temp = max(rob1+num,rob2);
            rob1= rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
/*
when we have the costs of each house
[1,2,3,1]
we check till first ind max is 1
then we check till ind 2 max is 2
at 3rd in the cost of 1st and 3rd is more than 2nd so 3
at 4th cost of 2nd and 1 is les than computed at 3rd ind
*/