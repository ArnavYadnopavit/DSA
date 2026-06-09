#include <iostream>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int l,r;
        for(int i = 0 ; i < n ; i++){
            l = i;
            r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                count+=1;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                count+=1;
                l--;
                r++;
            }
        }
        return count;
    }
};
