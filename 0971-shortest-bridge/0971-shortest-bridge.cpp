class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    void dfs(int row,int col ,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 ){
            return ;
        }
        grid[row][col] = -1;
        for(int i=0;i<4;i++){
            int x = row + dx[i];
            int y = col + dy[i];
            if(x >= 0 && y >= 0 &&  x < n && y < m && grid[x][y] == 1){
                dfs(x,y,grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        
        bool ok = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 1){
                    dfs(i,j,g);
                    ok = 1;
                    break;
                }
            }
            if(ok == 1)break;
        }
       
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(g[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = row + dx[i];
                int y = col + dy[i];
                if(x>=0 && y >= 0 && x < n && y < m && !vis[x][y]){
                    vis[x][y] = 1;
                    dis[x][y] += dis[row][col] + 1;
                    q.push({x,y});
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == -1){
                    ans = min(ans,dis[i][j]);
                }
              
            }

        }
        return ans-1;
        
    }
};