class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    bool vis[505][505];
    void dfs(int row,int col , vector<vector<int>>&grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || vis[row][col] == 1 || grid[row][col] == 0){
            return;
        }
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int x = dx[i] + row;
            int y = dy[i] + col;
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !vis[x][y] && grid[x][y] == 1){
                dfs(x,y,grid);
            }
        }
    
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0,i,grid);
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1,i,grid);
            }
        }for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,grid);
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<vis[i][j]<< " ";
                if( grid[i][j] == 1 && vis[i][j] == 0)cnt++;
            }//cout<<endl;
        }
        return cnt;
    }
};