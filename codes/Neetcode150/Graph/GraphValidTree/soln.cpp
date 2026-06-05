#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
    return false;
        //if(n==1) return true;
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
        if(!dfs(visited,graph,0,prev))return false;
        if(visited.size()==n){
            return true;
        }
        return false;
    }
private:
    bool dfs(unordered_set <int> &visited,vector<vector<int>> &graph,int i, int prev){
        if(visited.count(i)) return false;
        visited.insert(i);
        for(auto num:graph[i]){
            if(num!=prev){
                if(!dfs(visited,graph,num,i)) return false;
            }
        }

        return true;
    }
};
