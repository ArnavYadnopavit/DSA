#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums = candidates;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> combsum;
        dfs(nums, ret, combsum, target, 0, 0);
        return ret;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>> &ret, vector<int> &c, int target, int sum, int i){
        if(sum == target){
            ret.push_back(c);
            return;
        }
        if(i>=nums.size() || sum>target){
            return;
        }
        for(int j = i;j<nums.size();j++){
            sum += nums[j];
            c.push_back(nums[j]);
            dfs(nums,ret,c,target,sum,j+1);
            sum-=nums[j];
            c.pop_back();
            while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
        }
        return;
    }
};
