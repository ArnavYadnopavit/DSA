#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(nums,perm,res);
        return res;
    }

private:
    void backtrack(const vector<int> &nums, vector<int> &perm, vector<vector<int>> &res){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }
        for(int num : nums){
            if(find(perm.begin(),perm.end(),num)!=perm.end()){
                continue;
            }
            else{
                perm.push_back(num);
                backtrack(nums,perm,res);
                perm.pop_back();
            }
        }
    }

    
};
