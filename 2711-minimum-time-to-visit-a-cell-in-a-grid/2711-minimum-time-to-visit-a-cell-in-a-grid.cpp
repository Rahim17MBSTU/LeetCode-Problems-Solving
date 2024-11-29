class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        //vector<vector<int>> res(n,vector<int>(m,0));
        
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            
             if (row == n - 1 && col == m - 1) {
               
                return dis;
            }
            if (vis[row][col]) continue;
            vis[row][col] = true;
            
         
            
            for (int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                
                if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y]) {
                    if (dis + 1 >= grid[x][y]) {
                        pq.push({dis + 1, {x, y}});
                        //res[x][y] = dis+1;
                    } else {
                        int wait_time = grid[x][y] - dis;
                        int next_time = (wait_time % 2 == 0) ? grid[x][y]+1 : grid[x][y];
                        pq.push({next_time, {x, y}});
                         //res[x][y] = next_time;
                    }
                }
            }
        }
        
        return -1;
    }
};
