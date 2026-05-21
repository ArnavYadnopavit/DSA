#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,areamax=0;
        while(l<r){
            int area=min(heights[l],heights[r])*(r-l);
            areamax = max(area,areamax);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return areamax;
    }
};
