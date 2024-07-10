class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1 ;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //cout <<"row= "<<row<<" col= "<<col<<endl;
            for(int i=0;i<4;i++){
                int x = row + dx[i];
                int y = col + dy[i];
                //cout <<"   x = "<<x<<" y = "<<y<<endl;
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || vis[x][y] == 1){
                    continue;
                }//cout<<"    queue push = "<<x<<" "<<y<<endl;
                res[x][y]+=res[row][col]+1;
                q.push({x,y});
                vis[x][y] = 1;
            }
            
        }
        return res;
    }
};