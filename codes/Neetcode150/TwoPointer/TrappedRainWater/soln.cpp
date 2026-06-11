#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r=1;
        int n = height.size();
        int ret=0;
        vector <int> preprocess(n,-1);
        while(r<n){
            if(height[l]<=height[r]){
                preprocess[l]=r;
                l=r;
            }
            
                r++;
        }
        l=n-2;
        r=n-1;
        while(l>=0){
            if(height[r]<height[l] || (height[r]==height[l] && preprocess[l]==-1)){
                preprocess[r]=l;
                r=l;
            }
                l--;
        }
        l=0;
        r=1;
        for(int i = 0; i<n;i++){
            cout << ret << " " << i << " " << preprocess[i] << endl;
            if(preprocess[i]==-1 || height[i]==0){
                continue;
            }
            else if(preprocess[i]>i){
                l=i;
                r=i+1;
                int h = height[l];
                while(r<preprocess[i]){
                    ret+=(height[l]-height[r]);
                    r++;
                }
            }
            else{
                r=i;
                l=i-1;
                int h = height[r];
                while(l>preprocess[i]){
                    ret+=(height[r]-height[l]);
                    l--;
                }
            }
        }
        return ret;
    }
};
