#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_set <int> visit;
        if(grid.size()==0) return 0;
        int rows = grid.size();
        int cols = grid[0].size() ;
        int islands = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if(grid[i][j]=='1'){
                    if(visit.count(i*cols+j)==0){
                        bfs(grid,visit,i,j);
                        islands+=1;
                    }
                }
            }
        }
        return islands;
    }
private:
    void bfs(vector<vector<char>> &grid,unordered_set<int>& s,int i,int j){
        queue <pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        q.push({i,j});
        s.insert(i*cols+j);
        while(q.size()>0){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            if(i>0 ){//UP
            if(grid[i-1][j]=='1' && s.count((i-1)*cols+j)==0){
                q.push({i-1,j});
                s.insert((i-1)*cols+j);
                }
            }
            if(j>0 ){//LEFT
            if(grid[i][j-1]=='1' && s.count(i*cols+j-1)==0){
                q.push({i,j-1});
                s.insert(i*cols+j-1);
                }
            }
            if(i<rows-1){//DOWN
            if(grid[i+1][j]=='1' && s.count((i+1)*cols+j)==0){
                q.push({i+1,j});
                s.insert((i+1)*cols+j);
                }
            }
            if(j<cols-1){//RIGHT
            if(grid[i][j+1]=='1' && s.count(i*cols+j+1)==0){
                q.push({i,j+1});
                s.insert(i*cols+j+1);
                }
            }

            
        }
    }
};