#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l=0,r;
        vector<int> ret;
        unordered_map <char,int> freq;
        for(auto c:s) {
            freq[c]++;
        } 
        while(l<s.size()){
            unordered_set <char> sub;
            for(r=l;r<s.size();r++){
                sub.insert(s[r]);
                freq[s[r]]--;
                int temp=0;
                for(auto c:sub){
                    cout << c <<r;
                    if (freq[c]!=0){
                        temp=1;
                        break;
                    }
                }
                if(!temp) break;
            }
            ret.push_back(r-l+1);
            l=r+1;
        }
        return ret;
    }
};
