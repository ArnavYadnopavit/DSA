#include <iostream>
#include <vector>
using namespace std;
class DSU{
    private:
    vector<int> parent;
    public:
    DSU(int n){
        parent.assign(n,-1);
    }
    int find(int x){
        if(parent[x]<0){
            return x;
        }
        return find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(parent[a]>parent[b]){
            parent[b]+=parent[a];
            parent[a]=b;
        }
        else{
            parent[a]+=parent[b];
            parent[b]=a;
        }
        return true;
    } 
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu = DSU(edges.size()+1);
        for(auto edge:edges){
            if(!dsu.unite(edge[0],edge[1])) return edge;
        }
        return {};

    }
};

