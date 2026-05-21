#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int maxlen=1,len=1;

        for(int i=1;i<sorted.size();i++){
            cout << sorted[i] << " ";
            if(sorted[i]==sorted[i-1]) continue;
            else if(sorted[i]==sorted[i-1]+1) {
                len+=1;
                cout << "yes";
            }
            else{
                maxlen=max(maxlen,len);
                len=1;
            }
        }
        maxlen=max(maxlen,len);
        return maxlen;
    }
};
