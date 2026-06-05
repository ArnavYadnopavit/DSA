#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int,vector<int>> premap;
        for(int i=0;i<numCourses;i++){
            premap[i]={};
        }
        for(auto pre:prerequisites){
            premap[pre[0]].push_back(pre[1]);
        }
        bool status=true;
        unordered_set <int> visit;
        
        unordered_set <int> cycle;
        vector<int> ret;
        for(int i=0;i<numCourses;i++){
            vector<int> temp;
            status = dfs(prerequisites,premap,ret,cycle,visit,i);
            if(!status) break;
        }
        if(!status) return {};
        return ret;

        
    }
bool dfs(vector<vector<int>> & prereq,unordered_map <int,vector<int>> &premap,vector<int> &order ,unordered_set <int> &cycle,unordered_set <int> &v,int pre){

    if(cycle.count(pre)==1) return false;
    if(v.count(pre)==1) return true;
    cycle.insert(pre);
    for(auto crs:premap[pre]){
    if(!dfs(prereq,premap,order,cycle,v,crs)) return false;
    }
    cycle.erase(pre);
    premap[pre]={};
    v.insert(pre);
    order.push_back(pre);
    return true;
}
};
