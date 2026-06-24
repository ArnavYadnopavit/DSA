#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        stack <int> open;
        stack <int> star;
        int i=0;
        for(auto c:s){
            if(c=='(') open.push(i);
            else if(c=='*') star.push(i);
            else if(c==')'){
                if(!open.empty())open.pop();
                else if(!star.empty())star.pop();
                else return false;
            }
            cout << c << open.size() << star.size() <<endl; 
            i++;
        }
        while(!open.empty() && !star.empty()){
            if(open.top()>star.top()) {
                return false;
            }
            open.pop();
            star.pop();
        }
        if(open.empty()) return true;
        return false;
    }
};
