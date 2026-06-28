#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int month=0;
        int week=0;
        int cur=0;
        vector<int> dp(n+1,INT_MAX/2);
        dp[0]=0;
        dp[1]=*min_element(costs.begin(),costs.end());
        for(cur=1;cur<n;cur++){
            
            while(days[cur]-days[month]>29) month++;
            while(days[cur]-days[week]>6) week++;
            dp[cur+1]=min(dp[cur]+costs[0],min(dp[week]+costs[1],dp[month]+costs[2]));
            cout<<dp[cur+1] <<" "<<days[week]<<" "<<days[month]<<endl;
        }
        return dp[n];
    }
};