#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        
        backtrack(res,subset,nums,0);

        return res;
    }
private:
void backtrack(vector<vector<int>> &res,vector<int>&subset, vector<int>& nums, int i){
            if(i>=nums.size()){
                res.push_back(subset);
                return;
            }

            subset.push_back(nums[i]);
            backtrack(res,subset,nums,i+1);
            subset.pop_back();
            backtrack(res,subset,nums,i+1);
        }
};
