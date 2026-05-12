#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.size(),ret=0;
        for(i=0;i<n;i++){
            int j=i;
            unordered_map <char,int> track;
            int substrlen = 0;
            while(j<n){
                if(track.find(s[j])==track.end()){
                    track[s[j]]=1;
                    substrlen++;
                    j++;
                }
                else{
                    break;
                }
            }
            if (ret<substrlen) ret=substrlen;
        }
        return ret;
    }
};
//Brute force used