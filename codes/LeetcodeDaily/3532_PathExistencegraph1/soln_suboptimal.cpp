class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        
        vector <vector<int>> intervals;
        int l=0;
        for(int r=0;r<n-1;r++){
            if(nums[r+1]-nums[r]<=maxDiff) continue;
            else{
                intervals.push_back({nums[l],nums[r]});
                l=r+1;
            }
        }
        //intervals[m-1][1]!=nums[n-1]
        int m = intervals.size();
        if(l<n) {
            intervals.push_back({nums[l],nums[n-1]});
            m++;
        }
        vector<bool> ret;
        //for (auto i:intervals) cout << i[0] << " " << i[1] << endl;
        for(auto q:queries){
            if(q[0]<=q[1]) ret.push_back(binsearch({nums[q[0]],nums[q[1]]},intervals,m));
            else ret.push_back(binsearch({nums[q[1]],nums[q[0]]},intervals,m));
        }
        return ret;
    }
private:
    bool binsearch(vector<int> q, vector<vector<int>>& inter,int m){
        auto it = upper_bound(
        inter.begin(),
        inter.end(),
        q[0],
        [](int val, const vector<int>& interval) {
            return val < interval[0];
        }
    );

    if (it == inter.begin())
        return false;   // no interval starts <= q[0]

    --it;   // last interval with start <= q[0]

    return q[1] <= (*it)[1];
    }
};
// O(n+qlogn)