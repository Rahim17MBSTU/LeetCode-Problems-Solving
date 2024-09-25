class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int x = entrance[0];
        int y = entrance[1];
        int mn = INT_MAX;
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        vector<vector<bool>>vis(n+10,vector<bool>(m+10,0));
        vector<vector<int>>dis(n+10,vector<int>(m+10,0));
        vis[x][y] = 1;
        dis[x][y] = 0;
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
              int x1 = x + dx[i];
              int y1 = y + dy[i];
              if(x1 >=0 && y1 >= 0 && y1 < m && x1 < n && !vis[x1][y1]  && maze[x1][y1] =='.'){
                dis[x1][y1] = dis[x][y] + 1;
                vis[x1][y1] = 1;
                q.push({x1,y1});
                if(x1 == 0 || x1 == n-1){
                    mn = min(dis[x1][y1],mn);
                }if(y1 == 0 || y1 == m-1){
                    mn = min(dis[x1][y1],mn);
                }
              }
            }    
        }
        return mn == INT_MAX ? -1 : mn;
    }
};