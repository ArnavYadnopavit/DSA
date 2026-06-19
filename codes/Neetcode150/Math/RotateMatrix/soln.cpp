#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        waterimg(matrix);
        transpose(matrix);
    }
private: 
    void waterimg(vector<vector<int>> &mat){
        int n=mat.size();
        for(int i=0;i<n/2;i++){
            swaprows(mat[i],mat[n-i-1]);
        }
    }
    void swaprows(vector<int> &a,vector<int>&b){
        for(int i=0;i<a.size();i++){
            swap(a[i],b[i]);
        }
    }
    void swap(int &a,int &b){
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void transpose(vector<vector<int>> &mat){
        int n=mat.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
