#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string par;
        dfs(ret,par,n,0);
        return ret;
    }
private:
    void dfs(vector<string> &ret, string &par, int n, int open_till_now){
        
        if(open_till_now>n || open_till_now<0 || par.size()>2*n) return;
        if(par.size()==2*n && open_till_now==0){
            ret.push_back(par);
            return;
        }

        par+='(';
        dfs(ret,par,n,open_till_now+1);
        par.pop_back();
        par+=')';
        dfs(ret,par,n,open_till_now-1);
        par.pop_back();
        return;
    }
};
