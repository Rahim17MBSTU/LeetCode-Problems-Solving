class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        for(int i=0;i<edges.size();i++){
           int x = edges[i][0];
           int y = edges[i][1];
           g[x].push_back(y);
           g[y].push_back(x);
        }
        int ans = 1e9;
        for(int i=0;i<n;i++){
            vector<int>dis(1001,1e9),par(1001,-1);
            queue<int>q;
            q.push(i);
            dis[i] = 0;
            while(!q.empty()){
                int source = q.front();
                q.pop();
                for(auto u:g[source]){
                    if(dis[u] == 1e9){
                        dis[u] = dis[source] + 1;
                        par[u] = source ;
                        q.push(u);
                    }
                    else if(par[source]!=u){
                        ans = min(ans,dis[u]+dis[source]+1);
                    }
                }
            }
        }
        if(ans == 1e9)return -1;
        else return ans;
    }
};