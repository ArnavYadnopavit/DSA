using PII = pair<int,int>;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        stack <int> st;
        vector<int> l(n);
        vector<int> r(n);
        for(int i=0;i<n;i++){
            while(!(st.empty()) && heights[st.top()]>=heights[i])st.pop();
            l[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!(st.empty()) && heights[st.top()]>=heights[i])st.pop();
            r[i]=st.empty()?n:st.top();
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(heights[i]*(r[i]-l[i]-1),maxarea);
        }
        return maxarea;
    }
};
