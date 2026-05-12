#include <iostream>
#include <vector>
using namespace std;
class MinStack {
private:
        vector<int> st;
        vector<int> minm;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minm.size()==0) minm.push_back(val);
        else if(*(minm.end()-1)>=val) minm.push_back(val);
        return;
    }
    
    void pop() {
        if(*(st.end()-1)==*(minm.end()-1)) minm.pop_back();
        st.pop_back();
        return;
    }
    
    int top() {
        return *(st.end()-1);
    }
    
    int getMin() {
        return *(minm.end()-1);
    }
};
