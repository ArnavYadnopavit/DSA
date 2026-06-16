#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> combsum;
        dfs(nums,ret,combsum,target,0,0);
        return ret;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &c, int target, int sum,int i){
        if(sum==target){
            ret.push_back(c);
            return;
        }
        if(sum>target || i>=nums.size()) return;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            c.push_back(nums[j]);
            dfs(nums,ret,c,target,sum,j);
            sum-=nums[j];
            c.pop_back();
        }
    } 
};
