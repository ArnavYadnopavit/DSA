#include <queue>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int>> pq;//min heap
        for(auto num:nums){
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();

    }
};
