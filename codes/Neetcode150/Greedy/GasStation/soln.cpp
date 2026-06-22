#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int sumgas=gas[n-1];
        int sumcost = cost[n-1];
        vector<int> cum(n);
        cum[n-1]=sumgas-sumcost;
        for(int i=n-2;i>=0;i--){
            sumgas+=gas[i];
            sumcost+=cost[i];
            cum[i]=gas[i]-cost[i]+cum[i+1];
        }
        if(sumgas<sumcost) return -1;
        int maxind = 0;
        for(int i=0;i<n;i++){
            if(cum[i]>=cum[maxind]) maxind=i;
        }
        return maxind;

    }
};

