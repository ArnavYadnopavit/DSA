#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res=stoi(tokens[0]);
        stack <int> st;
        for(auto token:tokens){
            if(!isop(token)) st.push(stoi(token));
            else{
                int b= st.top();
                st.pop();
                int a=st.top();
                st.pop();
                res = op(a,b,token);
                st.push(res);
            }
        }
        return res;
    }
private:
    bool isop(string token){
        if(token == "+" || token == "-" || token == "*" || token == "/")return true;
        return false;
    }
    int op(int a,int b,string token){
        if(token == "+") return a+b;
        else if(token == "-") return a-b;
        else if(token == "*") return a*b;
        else if(token == "/") return a/b;
    }
};
