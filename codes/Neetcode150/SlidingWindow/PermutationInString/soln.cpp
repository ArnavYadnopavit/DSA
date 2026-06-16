#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;
        vector <int> freq(26,0);
        for(auto c:s1){
            freq[c-'a']++;
        }
        int l=0,r=0,count = n;
        for(r=0;r<m;r++){
            if(freq[s2[r]-'a']>0) count--;
            freq[s2[r]-'a']--;
            if(r-l+1>n){
                if(++freq[s2[l++]-'a']>0) count++;
            }
            //cout << l << r << count << endl;
            if(!count) return true;
        }
        return false;
    }
};
