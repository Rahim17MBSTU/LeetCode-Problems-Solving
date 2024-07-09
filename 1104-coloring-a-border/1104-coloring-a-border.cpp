class Solution {
public:
    int dx[8] = {-1, 1, 0, 0};
    int dy[8] = {0, 0, -1, 1};
    bool vis[55][55];
    void dfs(int row,int col , int color, vector<vector<int>>& grid, int n,int m,int init_col,vector<vector<int>>& grid1){
        
        if(row <0 || col <0 || row>= n || col >= m || grid[row][col]!= init_col || vis[row][col] == 1)return;
        bool ok = 0;
        if(row-1 >=0 && grid[row-1][col] != init_col){
            ok = 1;
            
            grid1[row][col] = color;
        }else if(row -1 < 0 && ok == 0 ){
            ok = 1;
            
            grid1[row][col] = color;
        }
        if(row+1 <n && grid[row+1][col] != init_col && ok == 0){
            ok = 1;
            grid1[row][col] = color;
        }else if(row+1 ==n  && ok == 0){
            ok = 1;
            grid1[row][col] = color;
        }if(col-1 >=0 && grid[row][col-1] != init_col && ok == 0){
            ok = 1;
            grid1[row][col] = color;
        }else if(col-1 <0  && ok == 0){
            ok = 1;
            grid1[row][col] = color;
        }if(col+1 <m && grid[row][col + 1] != init_col && ok ==0){
            ok = 1;
            grid1[row][col] = color;
        }else if(col+1 ==m && ok ==0){
            ok = 1;
            grid1[row][col] = color;
        }
       
        
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int x = dx[i] + row;
            int y = dy[i] + col;
            dfs(x,y,color,grid,n,m,init_col,grid1);
            
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int init_col = grid[row][col];
        vector<vector<int>> grid1 = grid;
        dfs(row,col,color,grid,n,m,init_col,grid1);
        return grid1;
    }
};