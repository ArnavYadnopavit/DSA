#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set <int> visited;
        int maxarea=0;
        for(int i=0; i<rows; i++){
            for(int j = 0; j < cols ; j++){
                if(grid[i][j]==1 && visited.count(i*cols+j)==0){
                int area = dfs(grid, visited, i,j);
                maxarea = max(area,maxarea);
                cout << area << endl;
                }
            }
        }
        return maxarea;
    }
private:
int dfs(vector<vector<int>>& grid, unordered_set <int>& s, int i, int j){
    int rows = grid.size(),cols = grid[0].size(),area = 1;
    deque<pair<int,int>> dq;
    dq.push_front({i,j});
    s.insert(i*cols+j);
    while(dq.size()>0){
        i=dq.front().first;
        j=dq.front().second;
        dq.pop_front();
            if(i>0 ){//UP
            if(grid[i-1][j]==1 && s.count((i-1)*cols+j)==0){
                dq.push_front({i-1,j});
                s.insert((i-1)*cols+j);
                area++;
                }
            }
            if(j>0 ){//LEFT
            if(grid[i][j-1]==1 && s.count(i*cols+j-1)==0){
                dq.push_front({i,j-1});
                s.insert(i*cols+j-1);
                area++;
                }
            }
            if(i<rows-1){//DOWN
            if(grid[i+1][j]==1 && s.count((i+1)*cols+j)==0){
                dq.push_front({i+1,j});
                s.insert((i+1)*cols+j);
                area++;
                }
            }
            if(j<cols-1){//RIGHT
            if(grid[i][j+1]==1 && s.count(i*cols+j+1)==0){
                dq.push_front({i,j+1});
                s.insert(i*cols+j+1);
                area++;
                }
            }
    }
    return area;
}
};