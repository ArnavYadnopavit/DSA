#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> arr1(n);
        vector<int> arr2(n);
        arr1[0] = 1;
        arr2[n-1]=1;
        for (int i=1;i<n;i++){
            arr1[i]=arr1[i-1]*nums[i-1];
            arr2[n-1-i] = arr2[n-i]*nums[n-i];
        }
        for(int i=0;i<n;i++){
            res[i] = arr1[i]*arr2[i];
        }
        return res;
    }
};