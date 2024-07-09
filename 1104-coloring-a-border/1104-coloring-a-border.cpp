class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = { 0,-1,1,0};
    bool vis[55][55];
    void dfs(int row,int col, vector<vector<int>>&grid,int color,int rep_col){
        grid[row][col] = -color;
        vis[row][col] = 1;
        int cnt = 0;
        for(int i=0;i<4;i++){
            int x = row + dx[i];
            int y = col + dy[i];
            cout<<x<<" "<<y<<endl;
            if(x < 0 || y < 0 || x >=grid.size() || y >= grid[0].size() || abs(grid[x][y]) != color ){
                cout<<"aise1 \n";
                continue;
            }
            cnt++;
            if(!vis[x][y] && grid[x][y] == color){
                cout<<"aise2 = "<<cnt<<endl;;
                dfs(x,y,grid,color,rep_col);
            }
            cout<<"cnt= "<<cnt<<endl;
            
        }
        if(cnt == 4){
                grid[row][col] = color;
                cout<<"row ="<<row<<" col= "<<col<<endl;
         }


    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        dfs(row,col,grid,grid[row][col],color);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] < 0) grid[i][j] = color;   
            }
        }
        return grid;
    }
};