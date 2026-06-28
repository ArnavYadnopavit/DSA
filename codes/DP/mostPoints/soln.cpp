#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        vector<long long> dp(n+1,0);
        for(long long i=n-1;i>=0;i--){
            if(i+questions[i][1]+1<=n)dp[i]=max(dp[i+1],dp[i+questions[i][1]+1]+questions[i][0]);
            else dp[i]=max(dp[i+1],(long long)questions[i][0]);
        }
        return dp[0];
    }

};