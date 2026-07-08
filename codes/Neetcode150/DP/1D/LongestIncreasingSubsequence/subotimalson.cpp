class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxx=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
            }
            maxx=max(maxx,dp[i]);
        }
        return maxx;
        
    }
};