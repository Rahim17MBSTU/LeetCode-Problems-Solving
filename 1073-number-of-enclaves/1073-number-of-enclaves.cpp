class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int cnt = 0 , answer = 0;
    bool vis[505][505], res = 1;
    void dfs(int row,int col,vector<vector<int>>&grid ){
        
        if((row == 0 || col == 0 || row == grid.size() - 1 || col == grid[0].size()-1 ) && grid[row][col] == 1){
                res &= 0;
        }
        if(row <0 || col <0 || row>=grid.size() || col >= grid[0].size() || grid[row][col] == 0 || vis[row][col] == 1){
            
            return;
        }
        cnt++;
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int x = dx[i] + row;
            int y = dy[i] + col;
            if(x>=0 && y >= 0 && x < grid.size() && y < grid[0].size() && !vis[x][y] && grid[x][y] == 1){
                dfs(x,y,grid);
            }
        }
        //return res;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j] == 0 ){
                    dfs(i,j,grid);
                    if(res == 1)
                    answer += cnt;
                }
                cnt = 0;
                res = 1;
            }
        }
        return answer ;
    }
};