#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> numpad={"abc","def","ghi",
                               "jkl","mno","pqrs",
                               "tuv","wxyz"};
        vector<string> ret;
        string dig;
        dfs(ret,dig,numpad,digits,0);
        return ret;
    }
private:
    void dfs(vector<string> & ret, string dig, const vector<string> &numpad, string digits, int idx){
        if(idx==digits.size()){
            ret.push_back(dig);
            return;
        }
        for(auto c:numpad[digits[idx]-'2']){
            dig.push_back(c);
            dfs(ret,dig,numpad,digits,idx+1);
            dig.pop_back();
        }
        return;
    }
};
