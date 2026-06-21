#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ret=digits;
        int c=1;
        for(int i=digits.size()-1;i>=0;i--){
            int sum = digits[i]+c;
            ret[i] = sum%10;
            c=sum/10;
            if(!c) break;
        }
        if(c) ret.insert(ret.begin(),c);
        return ret;
    }
};
