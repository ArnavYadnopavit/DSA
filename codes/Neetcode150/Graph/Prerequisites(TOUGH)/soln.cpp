#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int,vector<int>> premap;
        for(int i=0;i<numCourses;i++){
            premap[i]={};
        }
        for(int i=0;i<prerequisites.size();i++){
            premap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set <int> visited;
        for(int i=0;i<numCourses;i++){
            if(!dfs(prerequisites, visited, premap, i)) return false;
        }
        return true;
    }
bool dfs(vector<vector<int>> &prereq, unordered_set <int> &v, unordered_map <int,vector<int>>& premap, int i){
    if(v.count(i)) return false;
    if(!premap[i].size()) return true;
    v.insert(i);
    for(auto crs: premap[i]){
        if(!dfs(prereq, v, premap, crs)) return false;
    }
    v.erase(i);
    premap[i]={};
    return true;
    
}
};
