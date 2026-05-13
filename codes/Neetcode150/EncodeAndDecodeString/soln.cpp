#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res={};
        int len;
        for(int i=0;i<strs.size();i++){
            len = strs[i].size();
            res.push_back((unsigned char)len);
            res+=strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0,len;
        while(i<s.size()){
            string temp;
            int j=0;
            len=(unsigned char)s[i];
            for (j=0;j<len;j++){
                temp.push_back(s[i+j+1]);
            }
            res.push_back(temp);
            i+=j+1;
        }
        return res;
    }
};
