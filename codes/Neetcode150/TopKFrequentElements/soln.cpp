#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])!=freq.end()) freq[nums[i]]+=1;
            else freq[nums[i]]=1;
        }
        priority_queue<pair<int,int>> pq;
        for(auto p:freq){
            pq.push({p.second,p.first});
        }
        vector<int> ret={};
        for(int i=0;i<k;i++){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
