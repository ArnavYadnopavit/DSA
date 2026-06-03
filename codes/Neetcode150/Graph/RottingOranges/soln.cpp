#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> rot_map;
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size(); 
        int fresh=0,time=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) fresh+=1;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(q.size()>0 && fresh>0){
            int layersize = q.size();
            for(int l=0;l<layersize;l++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                helper(grid,q,fresh,i-1,j,rows,cols);//LEFT
                helper(grid,q,fresh,i+1,j,rows,cols);//RIGHT
                helper(grid,q,fresh,i,j-1,rows,cols);//UP
                helper(grid,q,fresh,i,j+1,rows,cols);//DOWN
            }
            time+=1;

        }
        if(fresh) return -1;
        else return time;
    }
private:
void helper(vector<vector<int>>& grid, queue <pair<int,int>>& q,int& fresh,int i,int j,int rows,int cols ){
    if(i>=0 && j>=0 && i<rows && j<cols && grid[i][j]==1){
        grid[i][j]=2;
        q.push({i,j});
        fresh-=1;
    }
    return;
}
};
