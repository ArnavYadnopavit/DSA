#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> sub;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        dfs(sorted,ret,sub,0);
        return ret;
    }
private:
    void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &s, int i){
            if(i>=nums.size()){
                ret.push_back(s);
                return;
            } 
            s.push_back(nums[i]);
            dfs(nums,ret,s,i+1);
            while(i+1<nums.size() && nums[i]==nums[i+1])i++;
            if(i==nums.size()) return;
            s.pop_back();
            dfs(nums,ret,s,i+1);
            }

};
