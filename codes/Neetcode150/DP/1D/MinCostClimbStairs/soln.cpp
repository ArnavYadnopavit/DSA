#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        for(int i = n-3 ; i>=0;i--){
            cost[i]=cost[i]+ min(cost[i+1],cost[i+2]);
        }
        return min(cost[0],cost[1]);
    }
/*
Let some array [10,15,20]
we start from back
from index 2 cost is 20
from index 1 cost is 15 or 15+20 so anyways min is 15
for index 0 cost to reach top is min(ind1,ind2)+ind0
*/
};
