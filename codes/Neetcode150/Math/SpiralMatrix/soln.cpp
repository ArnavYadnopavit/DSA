#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ret;
        int leftb=0,rightb=matrix[0].size(),upb=0,downb=matrix.size();//Defining bounds
        int count=rightb*downb;
        while(count){
            int i=upb;
            int j;
            for(j=leftb;j<rightb;j++){
                ret.push_back(matrix[i][j]);
                count--;
            }
            if(!count)break;
            j=rightb-1;
            upb++;
            for(i=upb;i<downb;i++){
                ret.push_back(matrix[i][j]);
                count--;
            }
            if(!count)break;
            rightb--;
            i=downb-1;
            for(j=rightb-1;j>=leftb;j--){
                ret.push_back(matrix[i][j]);
                count--;
            }
            
            if(!count)break;
            downb--;
            j=leftb;
            for(i=downb-1;i>=upb;i--){
                ret.push_back(matrix[i][j]);
                count--;
            }
            leftb++;

        }
        return ret;
    }
};
