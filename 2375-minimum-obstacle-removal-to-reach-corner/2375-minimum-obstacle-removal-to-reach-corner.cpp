class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[0][0] = 1;
        int result = 0;
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            if(row == n-1 && col == m-1){
                result = dis;
                break;
            }
            for(int i = 0 ;i < 4;i++){
                int x = dx[i] + row;
                int y = dy[i] + col;
                if(x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0){
                    vis[x][y] = 1;
                    int distance = dis + grid[x][y];
                    pq.push({distance,{x,y}});
                }
            }
            
        }
        return result;
    }
};