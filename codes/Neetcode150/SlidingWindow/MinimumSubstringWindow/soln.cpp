using PII = pair<int,int>;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> check;
        for(auto c:t){
            check[c]+=1;
        }
        int n=s.size();
        int t_size=t.size();
        int cnt=t.size();
        PII lr={-1,n-1};
        int l=0;
        for(int r=0;r<n;r++){
            auto c=s[r];
            if(check[c]>0){
                cnt-=1;
            }
            check[c]-=1;
            if(cnt==0){
                while(cnt==0){
                    check[s[l]]++;
                    if(check[s[l]]>0) cnt++;
                    l++;
                }
                if(r-l<=lr.second-lr.first){
                    lr={l,r};
                }
                if(r-l+2==t_size)break;
            }
        }
        if(lr.first==-1)return "";
        return s.substr(lr.first-1,lr.second-lr.first+2);
        
    }
};
