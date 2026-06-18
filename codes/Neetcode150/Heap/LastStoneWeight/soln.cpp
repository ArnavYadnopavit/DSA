#include <queue>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        priority_queue <int> pq;
        for(auto stone:stones){
            pq.push(stone);
        }
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        pq.push(abs(x-y));
        while(pq.size()>1){
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            pq.push(abs(x-y));
        }
        return pq.top();
    }
};
