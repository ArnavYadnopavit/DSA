#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set <int> visited;
        int prev=-1;
        vector<vector<int>> graph;
        for(int i=0;i<n;i++){
            graph.push_back({});
        }
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(visited.count(i)) continue;
            dfs(visited,graph,i,prev);
            count++;
        }
        return count;
    }
private:
    void dfs(unordered_set <int> &visited,vector<vector<int>> &graph,int i, int prev){
        if(visited.count(i)) return ;
        visited.insert(i);
        for(auto num:graph[i]){

            if(num!=prev)    dfs(visited,graph,num,i);
        }

        return ;
    }
    
};
