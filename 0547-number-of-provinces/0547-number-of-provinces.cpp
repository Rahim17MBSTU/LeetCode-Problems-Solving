class Solution {
public:
    static const int N = 205;
    vector<int>g[205];
    bool vis[N];
    void dfs(int source){
        vis[source] = 1;
        
        for(auto child:g[source]){
            if(!vis[child]){
                dfs(child);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        for(int i=0;i<n;i++){
            for(int j = 0 ;j <n;j++){
                if(isConnected[i][j] == 1){
                    g[i].push_back(j);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
           if(vis[i] == 0){
            dfs(i);
            cnt++;
           }
        }
        return cnt;
    }
};