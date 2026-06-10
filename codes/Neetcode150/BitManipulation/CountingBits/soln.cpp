#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n==1) return {0,1};
        vector <int> ret ={0,1};
        int idx = 2;
        int i=0;
        while(idx+i<=n){
            for(int i = 0;i<idx;i++){
                if(i+idx>n) break;
                ret.push_back(ret[i]+1);
            }
            idx = idx*2;
        }
        return ret;
    }
};
