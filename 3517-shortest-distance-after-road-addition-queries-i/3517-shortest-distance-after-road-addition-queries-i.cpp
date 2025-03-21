class Solution {
public:
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>g[n+1];
        for(int i=0;i<n;i++){
            g[i].push_back(i+1);
        }
        vector<int>res;    
        for(vector<int>v : queries){
            int x = v[0];
            int y = v[1];
            g[x].push_back(y);
            vector<int>dis(n+1,0);
            vector<bool>vis(n+1,0);
            vis[0] = 1;
            dis[0] = 0;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(int u:g[x]){
                    if(!vis[u]){
                        q.push(u);
                        dis[u] = dis[x] + 1;
                        vis[u] = 1;
                    }
                }
            }
           
            res.push_back(dis[n-1]);
        }
        
        return res;
    }
};