#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char,int> freq;
        int l =0,r=0,ret = 0;
        for(int i =0;i<26;i++){
            freq[i+'A'] = 0;
        }
        for(r=0;r<s.size();r++){
            freq[s[r]]++;
            while((r-l+1 - maxcount(freq))>k ){
                freq[s[l]] -=1;
                l++;
            }
            ret = max(ret,r-l+1);
        }
        return ret;
        
    }
int maxcount(unordered_map<char,int> & freq){
    int ret =0;
    for(int i = 0;i<26;i++){
        int f = freq[i+'A'];
        if(ret<f) ret = f; 
    }
    return ret;
}
};
