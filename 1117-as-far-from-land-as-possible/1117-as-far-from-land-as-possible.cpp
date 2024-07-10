class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int land = 0, water = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});land++;
                }else water++;
            }
        }

        if(land == n*m || water == n * m) return -1;
        int mx = 0;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = row + dx[i];
                int y = col + dy[i];
                if( x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0){
                    dis[x][y] = dis[row][col] + 1;
                    mx = max(dis[x][y] , mx);
                    grid[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout <<endl;
        // }
        return mx;
    }
};