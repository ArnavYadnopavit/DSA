#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.size(),ret=0;
        unordered_set<char> track;
        for(int r=0;r<n;r++){
            while(track.find(s[r])!=track.end()){
                track.erase(s[l]);
                l++;
            }
            track.insert(s[r]);
            ret = max(r-l+1,ret);
        }
        return ret;
    }
};
//Sliding window used
