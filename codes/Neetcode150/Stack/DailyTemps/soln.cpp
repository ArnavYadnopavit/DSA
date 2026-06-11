#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector <int> ret(n,0);
        for(int i=0;i<n;i++){
            int t = temperatures[i];
            while(!st.empty() && t>st.top().first){
                auto p = st.top();
                ret[p.second]=i-p.second;
                st.pop();
            }
            st.push({t,i});
        }
        return ret;
    }
};
