class Solution {
public:
    int dx[4] = { -1, 0 ,0, 1};
    int dy[4] = { 0 , -1 , 1, 0 };
    int orangesRotting(vector<vector<int>>& grid) {
        int FreshOrange = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(20,vector<int>(20,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)FreshOrange++;
                if(grid[i][j] == 2){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int minite = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = row + dx[i];
                int y = col + dy[i];
                if(x >= 0 && y >= 0 && x <n && y < m && grid[x][y] == 1 ){
                    grid[x][y] = 0;
                    dis[x][y] += dis[row][col] + 1;
                    minite = max(minite , dis[x][y]);
                    FreshOrange--; 
                    q.push({x,y});
                }
            }
        }
        if(FreshOrange == 0) return minite;
        return -1;

    }
};