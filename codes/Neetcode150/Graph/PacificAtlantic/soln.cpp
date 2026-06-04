#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pacific;
        queue<pair<int,int>> atlantic;
        unordered_set<int> pacific_visited;
        unordered_set<int> atlantic_visited;
        vector<vector<int>> ret;
        int rows = heights.size(),cols = heights[0].size();

        for(int i=0;i<rows;i++){
            pacific.push({i,0});
            atlantic.push({i,cols-1});
            pacific_visited.insert(i*cols);
            atlantic_visited.insert(i*cols+cols-1);
        }
        for(int j=1;j<cols;j++){
            pacific.push({0,j});
            atlantic.push({rows-1,j-1});
            pacific_visited.insert(j);
            atlantic_visited.insert((rows-1)*cols+j-1);
        }
        while(pacific.size()>0){
                int i = pacific.front().first;
                int j = pacific.front().second;
                pacific.pop();
                addhelper(heights, pacific, pacific_visited, i-1, j, rows, cols, heights[i][j]);
                addhelper(heights, pacific, pacific_visited, i+1, j, rows, cols, heights[i][j]);
                addhelper(heights, pacific, pacific_visited, i, j-1, rows, cols, heights[i][j]);
                addhelper(heights, pacific, pacific_visited, i, j+1, rows, cols, heights[i][j]);
            
        }
        while(atlantic.size()>0){
                int i = atlantic.front().first;
                int j = atlantic.front().second;
                atlantic.pop();
                addhelper(heights, atlantic, atlantic_visited, i-1, j, rows, cols, heights[i][j]);
                addhelper(heights, atlantic, atlantic_visited, i+1, j, rows, cols, heights[i][j]);
                addhelper(heights, atlantic, atlantic_visited, i, j-1, rows, cols, heights[i][j]);
                addhelper(heights, atlantic, atlantic_visited, i, j+1, rows, cols, heights[i][j]);
           
        }
        ret = intersection(pacific_visited,atlantic_visited,cols);
        return ret;

    }
private:
void addhelper(vector<vector<int>>& heights,queue<pair<int,int>> &q,unordered_set <int> &s,int i,int j, int rows,int cols,int height){
    if(i>=0 && j>=0 && i<rows && j<cols && heights[i][j]>=height && s.count(i*cols+j)==0){
        q.push({i,j});
        s.insert(i*cols+j);
    }
    return;
}
vector<vector<int>> intersection(unordered_set <int> & p, unordered_set <int> &q,int cols){
    vector<vector<int>> ret;
    if(p.size()<q.size()){
    for(auto coords:p){
        if(q.count(coords)==1) ret.push_back({coords/cols,coords%cols});
    }
    }
    else{
    for(auto coords:q){
        if(p.count(coords)==1) ret.push_back({coords/cols,coords%cols});
    }
    }
    return ret;
}
};
