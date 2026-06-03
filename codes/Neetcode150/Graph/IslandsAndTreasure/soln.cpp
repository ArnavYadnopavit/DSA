#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> treasure_map;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    treasure_map.push_back({i, j});
                }
            }
        }
        bfs(grid,treasure_map);
        return;
    }
private:
void helper(vector<vector<int>>& grid,queue <pair<int,int>>& q,int i,int j,int dist,int rows,int cols){
    
    if(i>=0 && j>=0 && i<rows && j<cols && grid[i][j]==INT_MAX){
        grid[i][j]=dist+1;
        q.push({i,j});
    }
    return;
}
void bfs(vector<vector<int>>& grid, vector<pair<int,int>>& treasure_map){
    queue <pair<int,int>> q;
    for(auto treasure: treasure_map){
        q.push(treasure);
    }
    int i,j,dist=0;
    int rows = grid.size();
    int cols = grid[0].size();

    while(q.size()>0){
        i=q.front().first;
        j=q.front().second;
        q.pop();
        helper(grid,q,i+1,j,grid[i][j],rows,cols);//RIGHT
        helper(grid,q,i-1,j,grid[i][j],rows,cols);//LEFT
        helper(grid,q,i,j+1,grid[i][j],rows,cols);//DOWN
        helper(grid,q,i,j-1,grid[i][j],rows,cols);//UP
    }
    return;
}
};
