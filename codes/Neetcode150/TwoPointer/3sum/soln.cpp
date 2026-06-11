#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        int n = nums.size();
        sort(sorted_nums.begin(),sorted_nums.end());
        vector<vector<int>> res = {};
        if(sorted_nums[0]==0 && sorted_nums[1]==0 && sorted_nums[2]==0) return vector<vector<int>>{{0,0,0}};
        if(sorted_nums[n-1]==0 && sorted_nums[n-2]==0 && sorted_nums[n-3]==0) return vector<vector<int>>{{0,0,0}};
        if(sorted_nums[0] >= 0 || sorted_nums[n-1]<= 0 ) return res;
        
        int l=0,c=1,r=n-1,lprev=-1,cprev=-1,rprev=-1;
        unordered_set <string>trip;
        for(c=1;c<n-1;c++){
            l=c-1;
            r=c+1;
            while(l>=0 && r<n){
                int a = sorted_nums[l];
                int b = sorted_nums[c];
                int p = sorted_nums[r];
                if(a+b+p==0){
                    string text = to_string(a)+","+to_string(b)+","+to_string(p);
                    if(!trip.count(text)){
                        trip.insert(text);
                        res.push_back({a,b,p});
                    }
                    l--;
                    r++;
                }
                else if(a+b+p>0)    l--;
                else                r++;
            }
        }
        return res;
    }
};
