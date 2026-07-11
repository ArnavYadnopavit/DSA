using PII = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> edges(n+1);
        for(auto edge:times){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            edges[u].push_back({w,v});
        }
        priority_queue <PII,vector<PII>,greater<PII>> pq;
        unordered_set <int> visited;
        pq.push({0,k});
        int maxpath = 0;
        while(!pq.empty()){
            PII node = pq.top();
            pq.pop();
            if (visited.count(node.second)) continue;

            visited.insert(node.second);
            maxpath = max(maxpath,node.first);
            for(auto e:edges[node.second]){
                if(!visited.count(e.second)){
                    pq.push({e.first+node.first,e.second});
                }
            }
        }
        if(visited.size()==n) return maxpath;
        return -1;
    }
};
