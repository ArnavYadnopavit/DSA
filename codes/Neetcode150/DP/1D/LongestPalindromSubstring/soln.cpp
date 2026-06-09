#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        int retsize = 0;
        int n = s.size();
        int l,r,size;
        for(int i=0;i<n;i++){
            
            l=i;
            r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            size = r-l-1;
            if(size > retsize){
                ret = s.substr(l+1,size);
                retsize = size;
            }
        
    
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            size = r-l-1;
            if(size > retsize){
                ret = s.substr(l+1,size);
                retsize = size;
            }
        }
        return ret;
    }
};
